#pragma once
// CommitGraph: the history of a repository as a directed acyclic graph (DAG).
//
// Each Commit points to its parents, so edges go from NEWER to OLDER commits.
// Example used in the tests and docs/graph-and-tree-design.md:
//
//        a1 <- b2 <- c3 <------- e5        (main)
//                \              /
//                 `--- d4 <----'           (feature, merged into main by e5)
//
//   e5 is a merge commit: parents = {c3, d4}.
//
// The graph OWNS its Commit objects (stored by value in a std::map keyed by
// ObjectId). Callers only get const access, so they cannot break the
// invariant "every parent of a stored commit is also stored".

#include "Commit.hpp"
#include "ObjectId.hpp"

#include <cstddef>
#include <map>
#include <optional>
#include <set>
#include <vector>

namespace minigit {

class CommitGraph {
public:
    // G1. Store a copy of commit. Return false (and change nothing) if a
    // commit with the same id already exists or if any parent is missing.
    // Because parents must exist first, the graph can never contain a cycle.
    bool addCommit(const Commit& commit);

    // G1. Lookup helpers.
    bool contains(const ObjectId& id) const;
    const Commit* find(const ObjectId& id) const; // nullptr if missing
    std::size_t size() const;

    // G2. First-parent history starting at start, newest first:
    // start, start's first parent, that commit's first parent, ... root.
    // This is what `git log --first-parent` shows. Empty if start is missing.
    std::vector<ObjectId> firstParentLog(const ObjectId& start) const;

    // G3. Every commit reachable from start by following ANY parent,
    // including start itself. Use breadth-first search with a std::queue.
    // Empty if start is missing.
    std::set<ObjectId> ancestors(const ObjectId& start) const;

    // G3. True if ancestor is reachable from descendant (a commit counts as
    // its own ancestor). False if either id is missing.
    bool isAncestor(const ObjectId& ancestor, const ObjectId& descendant) const;

    // G4. The merge base of a and b: a common ancestor of both that is
    // closest to b. Algorithm: compute ancestors(a); then BFS from b
    // (visiting parents in stored order) and return the first commit that is
    // also an ancestor of a. std::nullopt if there is none or an id is missing.
    std::optional<ObjectId> mergeBase(const ObjectId& a, const ObjectId& b) const;

    // G5 (stretch). All commits, newest first, such that every commit
    // appears before all of its parents (a topological order, like
    // `git log --topo-order`). Ties are broken by the smaller ObjectId first.
    std::vector<ObjectId> topologicalOrder() const;

private:
    std::map<ObjectId, Commit> commits_;
};

} // namespace minigit

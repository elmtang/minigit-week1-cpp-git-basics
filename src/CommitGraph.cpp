#include "CommitGraph.hpp"

#include <queue> // std::queue for breadth-first search

namespace minigit {

// Replace each placeholder body as you complete Issues G1-G5.
// Keep every signature unchanged so the tests keep compiling.

bool CommitGraph::addCommit(const Commit& commit) {
    // TODO(G1): reject duplicates, reject missing parents, then
    // commits_.emplace(commit.id(), commit).
    (void)commit;
    return false;
}

bool CommitGraph::contains(const ObjectId& id) const {
    // TODO(G1): use commits_.find(id) or commits_.count(id).
    (void)id;
    return false;
}

const Commit* CommitGraph::find(const ObjectId& id) const {
    // TODO(G1): return &it->second when found.
    (void)id;
    return nullptr;
}

std::size_t CommitGraph::size() const {
    // TODO(G1)
    return 0;
}

std::vector<ObjectId> CommitGraph::firstParentLog(const ObjectId& start) const {
    // TODO(G2): loop with a `const Commit*` that follows parents()[0].
    (void)start;
    return {};
}

std::set<ObjectId> CommitGraph::ancestors(const ObjectId& start) const {
    // TODO(G3): BFS. A std::set doubles as the "visited" list.
    (void)start;
    return {};
}

bool CommitGraph::isAncestor(const ObjectId& ancestor, const ObjectId& descendant) const {
    // TODO(G3): reuse ancestors().
    (void)ancestor;
    (void)descendant;
    return false;
}

std::optional<ObjectId> CommitGraph::mergeBase(const ObjectId& a, const ObjectId& b) const {
    // TODO(G4): ancestors(a), then BFS from b.
    (void)a;
    (void)b;
    return std::nullopt;
}

std::vector<ObjectId> CommitGraph::topologicalOrder() const {
    // TODO(G5, stretch): count children per commit, start from commits with
    // no children, and keep the ready commits in a std::set<ObjectId>.
    return {};
}

} // namespace minigit

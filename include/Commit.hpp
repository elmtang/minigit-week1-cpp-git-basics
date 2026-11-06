#pragma once
// Commit: one node of the commit graph.
//
// A commit knows its own id, its parent ids, and a message. (Real Git also
// stores the id of a file tree snapshot; see FileTree for that half.) It does NOT own its parents and does not hold
// pointers to them: parents are referred to by ObjectId, and CommitGraph
// looks them up. This is how real Git works, and it avoids dangling pointers.
//
//   0 parents -> root commit (the first commit of a repository)
//   1 parent  -> ordinary commit
//   2 parents -> merge commit (parents()[0] is the branch you were on)

#include "ObjectId.hpp"

#include <string>
#include <vector>

namespace minigit {

class Commit {
public:
    Commit(ObjectId id, std::vector<ObjectId> parents, std::string message);

    const ObjectId& id() const { return id_; }
    const std::vector<ObjectId>& parents() const { return parents_; }
    const std::string& message() const { return message_; }

    bool isRoot() const { return parents_.empty(); }
    bool isMerge() const { return parents_.size() >= 2; }

private:
    ObjectId id_;
    std::vector<ObjectId> parents_;
    std::string message_;
};

} // namespace minigit

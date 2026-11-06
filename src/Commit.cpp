#include "Commit.hpp"

#include <utility>

namespace minigit {

Commit::Commit(ObjectId id, std::vector<ObjectId> parents, std::string message)
    : id_(std::move(id)), parents_(std::move(parents)), message_(std::move(message)) {}

} // namespace minigit

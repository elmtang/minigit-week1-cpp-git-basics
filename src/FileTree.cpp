#include "FileTree.hpp"

#include <utility>

namespace minigit {

// Provided: construction and moving. A tree always starts with an empty
// root directory node.
FileTree::FileTree() : root_(std::make_unique<Node>()) {}
FileTree::~FileTree() = default;
FileTree::FileTree(FileTree&&) noexcept = default;
FileTree& FileTree::operator=(FileTree&&) noexcept = default;

// Replace each placeholder body as you complete Issues G6-G9.
// Tip: recursion is the natural way to walk a tree. Because Node is a
// private type, put recursive helpers in the PRIVATE section of
// FileTree.hpp, for example:
//     static void collectFiles(const Node& node, const std::string& prefix,
//                              std::vector<std::string>& out);
// Adding private helpers is allowed; changing public signatures is not.

bool FileTree::addFile(const std::filesystem::path& relativePath, const ObjectId& blob) {
    // TODO(G6): validate, walk/create directory nodes, then create or update the leaf.
    (void)relativePath;
    (void)blob;
    return false;
}

bool FileTree::containsFile(const std::filesystem::path& relativePath) const {
    // TODO(G6)
    (void)relativePath;
    return false;
}

std::optional<ObjectId> FileTree::blobOf(const std::filesystem::path& relativePath) const {
    // TODO(G6)
    (void)relativePath;
    return std::nullopt;
}

std::size_t FileTree::fileCount() const {
    // TODO(G7): recursion.
    return 0;
}

std::vector<std::string> FileTree::listFiles() const {
    // TODO(G7): depth-first, children in name order (std::map is already sorted).
    return {};
}

std::string FileTree::render() const {
    // TODO(G8)
    return ".\n";
}

TreeDiff FileTree::diff(const FileTree& newer) const {
    // TODO(G9): one approach compares listFiles() of both trees plus blobOf().
    (void)newer;
    return {};
}

} // namespace minigit

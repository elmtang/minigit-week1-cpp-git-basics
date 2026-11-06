#pragma once
// FileTree: an in-memory snapshot of a project's files, stored as a tree.
//
// Directories are internal nodes; files are leaves that remember the
// ObjectId of their contents (a "blob" in Git). Nothing here touches the
// disk: paths are only used as names.
//
//   .
//   |-- README.md
//   `-- src
//       |-- main.cpp
//       `-- util
//           `-- math.cpp
//
// Ownership: each node OWNS its children through std::unique_ptr, so the
// whole tree is freed automatically when the FileTree is destroyed. Because
// unique_ptr cannot be copied, FileTree is move-only.

#include "ObjectId.hpp"

#include <cstddef>
#include <filesystem>
#include <map>
#include <memory>
#include <optional>
#include <string>
#include <vector>

namespace minigit {

// Result of comparing an older tree with a newer one (G9). Each list holds
// generic paths ("src/main.cpp"), sorted alphabetically.
struct TreeDiff {
    std::vector<std::string> added;    // only in the newer tree
    std::vector<std::string> removed;  // only in the older tree
    std::vector<std::string> modified; // in both, different blob id
};

class FileTree {
public:
    FileTree();
    ~FileTree();
    FileTree(FileTree&&) noexcept;
    FileTree& operator=(FileTree&&) noexcept;
    FileTree(const FileTree&) = delete;
    FileTree& operator=(const FileTree&) = delete;

    // G6. Add (or replace) the file at relativePath, creating any missing
    // directory nodes on the way. Iterate over the path's parts with a
    // range-for loop: for (const auto& part : relativePath).
    // Return false and change nothing if:
    //   * relativePath is empty or absolute, or contains "." or "..";
    //   * a part that must be a directory is already a file
    //     (e.g. "a" is a file and you add "a/b.txt");
    //   * the final part is already a directory.
    bool addFile(const std::filesystem::path& relativePath, const ObjectId& blob);

    // G6. True only for files (not directories).
    bool containsFile(const std::filesystem::path& relativePath) const;

    // G6. Blob id of a file, or std::nullopt for a missing path or a directory.
    std::optional<ObjectId> blobOf(const std::filesystem::path& relativePath) const;

    // G7. Number of files (leaves) in the whole tree. Use recursion.
    std::size_t fileCount() const;

    // G7. Every file as a generic path ("src/util/math.cpp"), visiting
    // children in name order with a depth-first (preorder) traversal.
    std::vector<std::string> listFiles() const;

    // G8. A drawing like the comment at the top of this file: first line is
    // ".", children in name order, prefixes "|-- " / "`-- " for entries and
    // "|   " / "    " for the indentation under them. Every line ends with '\n'.
    std::string render() const;

    // G9. Compare this (older) tree with newer.
    TreeDiff diff(const FileTree& newer) const;

private:
    struct Node {
        bool isDirectory = true;
        std::optional<ObjectId> blob;                         // set for files only
        std::map<std::string, std::unique_ptr<Node>> children; // empty for files
    };

    std::unique_ptr<Node> root_; // always a directory node
};

} // namespace minigit

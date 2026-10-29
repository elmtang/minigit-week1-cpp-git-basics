#pragma once
#include <filesystem>

namespace minigit {

// Return the path to the metadata folder inside a repository.
// This builds a path only; it does not create the folder.
std::filesystem::path metadataDirectory(const std::filesystem::path& root);
// Return the path to the HEAD file inside the metadata folder.
std::filesystem::path headFile(const std::filesystem::path& root);
} // namespace minigit

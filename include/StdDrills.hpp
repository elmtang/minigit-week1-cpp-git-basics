#pragma once
// Standard-library class drills for MiniGit.
//
// Every function here is small and uses ONE standard-library class as its
// main tool. Functions named example* are complete worked examples: read them,
// run their tests, and copy the pattern. Functions named drill* are exercises:
// each one has a matching Issue draft in issue-drafts/ (S1-S5).
//
// Guide: docs/std-classes-guide.md

#include <filesystem>
#include <map>
#include <optional>
#include <string>
#include <vector>

namespace minigit::drills {

// ---------------------------------------------------------------------------
// Worked examples (already implemented and tested)
// ---------------------------------------------------------------------------

// std::string: true if text begins with prefix. Uses size() and compare().
bool exampleStartsWith(const std::string& text, const std::string& prefix);

// std::filesystem::path: the file name without its extension.
// "src/PathLab.cpp" -> "PathLab". Uses stem().
std::string exampleStem(const std::filesystem::path& file);

// std::vector: keep only the entries that end with the given extension.
// Uses push_back() and a range-for loop.
std::vector<std::filesystem::path> exampleFilterByExtension(
    const std::vector<std::filesystem::path>& files, const std::string& extension);

// std::map: count how many times each word appears. Uses operator[].
std::map<std::string, int> exampleWordCount(const std::vector<std::string>& words);

// std::optional + std::ifstream: whole file contents, or std::nullopt if the
// file cannot be opened.
std::optional<std::string> exampleReadAll(const std::filesystem::path& file);

// ---------------------------------------------------------------------------
// Drills (students implement these; see issue-drafts/05..09)
// ---------------------------------------------------------------------------

// S1 std::string. A HEAD file normally contains "ref: refs/heads/<branch>\n".
// Return the branch name ("main"). Return "" if the text does not start with
// "ref: refs/heads/". Remove a trailing '\n' or "\r\n" if present.
std::string drillBranchFromHead(const std::string& headText);

// S2 std::filesystem::path. Git stores object "a1b2c3..." at
// <root>/.minigit/objects/a1/b2c3...  (first two characters form a folder).
// Precondition: id.size() > 2.
std::filesystem::path drillObjectPath(const std::filesystem::path& root, const std::string& id);

// S3 std::vector + std::istringstream. Split text into lines. A final line
// without '\n' is still a line; an empty string gives an empty vector.
std::vector<std::string> drillSplitLines(const std::string& text);

// S4 std::map. Count files by extension (".cpp", ".hpp", ...). Files without
// an extension are counted under "(none)".
std::map<std::string, int> drillCountExtensions(const std::vector<std::filesystem::path>& files);

// S5 std::optional + std::ifstream + std::getline. First line of a file
// (without '\n'), or std::nullopt if the file cannot be opened or is empty.
std::optional<std::string> drillReadFirstLine(const std::filesystem::path& file);

} // namespace minigit::drills

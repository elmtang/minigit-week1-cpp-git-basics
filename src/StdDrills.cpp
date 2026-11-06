#include "StdDrills.hpp"

#include <fstream>
#include <sstream>

namespace minigit::drills {

// ---------------------------------------------------------------------------
// Worked examples
// ---------------------------------------------------------------------------

bool exampleStartsWith(const std::string& text, const std::string& prefix) {
    // compare(pos, count, other) compares text[pos, pos+count) with other.
    return text.size() >= prefix.size() && text.compare(0, prefix.size(), prefix) == 0;
}

std::string exampleStem(const std::filesystem::path& file) {
    // stem() returns a path; string() converts it to std::string.
    return file.stem().string();
}

std::vector<std::filesystem::path> exampleFilterByExtension(
    const std::vector<std::filesystem::path>& files, const std::string& extension) {
    std::vector<std::filesystem::path> result;
    for (const std::filesystem::path& file : files) {
        if (file.extension() == extension) {
            result.push_back(file);
        }
    }
    return result;
}

std::map<std::string, int> exampleWordCount(const std::vector<std::string>& words) {
    std::map<std::string, int> counts;
    for (const std::string& word : words) {
        ++counts[word]; // operator[] inserts 0 the first time a key is seen
    }
    return counts;
}

std::optional<std::string> exampleReadAll(const std::filesystem::path& file) {
    std::ifstream in(file, std::ios::binary);
    if (!in) {
        return std::nullopt; // "no value": the file could not be opened
    }
    std::ostringstream buffer;
    buffer << in.rdbuf();
    return buffer.str();
}

// ---------------------------------------------------------------------------
// Drills: replace each placeholder body. Keep the signature unchanged.
// ---------------------------------------------------------------------------

std::string drillBranchFromHead(const std::string& headText) {
    // TODO(S1): use exampleStartsWith, substr(), and back()/pop_back().
    (void)headText;
    return "";
}

std::filesystem::path drillObjectPath(const std::filesystem::path& root, const std::string& id) {
    // TODO(S2): use substr() to split id, then operator/ to join path parts.
    (void)root;
    (void)id;
    return {};
}

std::vector<std::string> drillSplitLines(const std::string& text) {
    // TODO(S3): wrap text in std::istringstream and loop with std::getline.
    (void)text;
    return {};
}

std::map<std::string, int> drillCountExtensions(const std::vector<std::filesystem::path>& files) {
    // TODO(S4): use extension(), empty(), and operator[] on the map.
    (void)files;
    return {};
}

std::optional<std::string> drillReadFirstLine(const std::filesystem::path& file) {
    // TODO(S5): open std::ifstream, check it, read one line with std::getline.
    (void)file;
    return std::nullopt;
}

} // namespace minigit::drills

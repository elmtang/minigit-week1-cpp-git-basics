// Tests for include/StdDrills.hpp.
//
// The example* tests already pass. When you work on a drill Issue (S1-S5),
// copy the starter tests from that Issue into the matching section below,
// watch them fail, then make them pass.

#include "StdDrills.hpp"
#include "TestHelpers.hpp"

#include <filesystem>
#include <fstream>

namespace fs = std::filesystem;
using namespace minigit::drills;

static void testExamples() {
    // std::string
    CHECK(exampleStartsWith("ref: refs/heads/main", "ref: "));
    CHECK(!exampleStartsWith("ref", "ref: "));
    CHECK(exampleStartsWith("anything", ""));

    // std::filesystem::path
    CHECK(exampleStem("src/PathLab.cpp") == "PathLab");
    CHECK(exampleStem("README") == "README");
    CHECK(exampleStem("archive.tar.gz") == "archive.tar"); // only the LAST extension

    // std::vector
    const std::vector<fs::path> files = {"a.cpp", "b.hpp", "src/c.cpp", "notes"};
    const std::vector<fs::path> cpp = exampleFilterByExtension(files, ".cpp");
    CHECK(cpp.size() == 2);
    CHECK(cpp.size() == 2 && cpp[0] == "a.cpp" && cpp[1] == "src/c.cpp");

    // std::map
    const std::map<std::string, int> counts = exampleWordCount({"add", "commit", "add"});
    CHECK(counts.size() == 2);
    CHECK(counts.at("add") == 2);
    CHECK(counts.at("commit") == 1);
    CHECK(counts.count("push") == 0);

    // std::optional + std::ifstream
    const fs::path dir = fs::temp_directory_path() / "minigit-std-drills-example";
    fs::create_directories(dir);
    {
        std::ofstream out(dir / "hello.txt", std::ios::binary);
        out << "hello\nworld\n";
    } // the ofstream closes (and flushes) here, at the end of its scope
    const std::optional<std::string> text = exampleReadAll(dir / "hello.txt");
    CHECK(text.has_value());
    CHECK(text.value_or("") == "hello\nworld\n");
    CHECK(!exampleReadAll(dir / "missing.txt").has_value());
    fs::remove_all(dir);
}

static void testS1BranchFromHead() {
    // TODO(S1): paste the starter tests from issue-drafts/05-std-string-head-ref.md
}

static void testS2ObjectPath() {
    // TODO(S2): paste the starter tests from issue-drafts/06-std-path-object-path.md
}

static void testS3SplitLines() {
    // TODO(S3): paste the starter tests from issue-drafts/07-std-vector-split-lines.md
}

static void testS4CountExtensions() {
    // TODO(S4): paste the starter tests from issue-drafts/08-std-map-count-extensions.md
}

static void testS5ReadFirstLine() {
    // TODO(S5): paste the starter tests from issue-drafts/09-std-optional-first-line.md
}

int main() {
    testExamples();
    testS1BranchFromHead();
    testS2ObjectPath();
    testS3SplitLines();
    testS4CountExtensions();
    testS5ReadFirstLine();
    return testing::testSummary("std_drills_tests");
}

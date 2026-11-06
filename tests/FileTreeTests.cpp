// Tests for FileTree.
//
// The empty-tree tests pass now. When you work on a tree Issue (G6-G9),
// copy the starter tests from that Issue into the matching section, watch
// them fail, then make them pass.

#include "FileTree.hpp"
#include "TestHelpers.hpp"

#include <utility>

using minigit::FileTree;
using minigit::ObjectId;
using minigit::TreeDiff;

static ObjectId id(const char* text) { return ObjectId(text); }

// The example tree from docs/graph-and-tree-design.md (needs G6 first):
// .
// |-- README.md
// `-- src
//     |-- main.cpp
//     `-- util
//         `-- math.cpp
[[maybe_unused]] static FileTree sampleTree() {
    FileTree t;
    t.addFile("README.md", id("aa"));
    t.addFile("src/main.cpp", id("bb"));
    t.addFile("src/util/math.cpp", id("cc"));
    return t; // returning a move-only object is fine: it is moved, not copied
}

static void testEmptyTree() {
    const FileTree t;
    CHECK(t.fileCount() == 0);
    CHECK(t.listFiles().empty());
    CHECK(t.render() == ".\n");
    FileTree moved = FileTree(); // move construction compiles and works
    CHECK(moved.fileCount() == 0);
}

static void testG6AddAndLookup() {
    // TODO(G6): paste the starter tests from issue-drafts/15-tree-add-lookup.md
}

static void testG7CountAndList() {
    // TODO(G7): paste the starter tests from issue-drafts/16-tree-count-list.md
}

static void testG8Render() {
    // TODO(G8): paste the starter tests from issue-drafts/17-tree-render.md
}

static void testG9Diff() {
    // TODO(G9): paste the starter tests from issue-drafts/18-tree-diff.md
}

int main() {
    testEmptyTree();
    testG6AddAndLookup();
    testG7CountAndList();
    testG8Render();
    testG9Diff();
    return testing::testSummary("file_tree_tests");
}

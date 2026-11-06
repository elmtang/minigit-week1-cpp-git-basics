// Tests for ObjectId, Commit, and CommitGraph.
//
// ObjectId and Commit are provided, finished classes: their tests pass now.
// When you work on a graph Issue (G1-G5), copy the starter tests from that
// Issue into the matching section, watch them fail, then make them pass.

#include "CommitGraph.hpp"
#include "TestHelpers.hpp"

#include <algorithm>
#include <stdexcept>

using minigit::Commit;
using minigit::CommitGraph;
using minigit::ObjectId;

static ObjectId id(const char* text) { return ObjectId(text); }

// The example history from docs/graph-and-tree-design.md:
//
//        a1 <- b2 <- c3 <------- e5        (main)
//                \              /
//                 `--- d4 <----'           (feature)
//   f6 is a separate root with no relation to the others.
//
// It only works once G1 (addCommit) is done.
[[maybe_unused]] static CommitGraph sampleGraph() {
    CommitGraph g;
    g.addCommit(Commit(id("a1"), {}, "initial commit"));
    g.addCommit(Commit(id("b2"), {id("a1")}, "add PathLab"));
    g.addCommit(Commit(id("c3"), {id("b2")}, "add HEAD path"));
    g.addCommit(Commit(id("d4"), {id("b2")}, "feature: write text"));
    g.addCommit(Commit(id("e5"), {id("c3"), id("d4")}, "Merge feature into main"));
    g.addCommit(Commit(id("f6"), {}, "unrelated root"));
    return g;
}

static void testObjectIdAndCommit() {
    CHECK(id("c0ffee").text() == "c0ffee");
    CHECK(id("0123456789abcdef").shortText() == "0123456");
    CHECK(id("a1").shortText() == "a1");
    CHECK(id("a1") == id("a1"));
    CHECK(id("a1") != id("b2"));
    CHECK(id("a1") < id("b2"));
    CHECK(!ObjectId::isValidText(""));
    CHECK(!ObjectId::isValidText("ABC"));
    CHECK(!ObjectId::isValidText("xyz"));

    // The constructor protects the class invariant by throwing.
    bool threw = false;
    try {
        ObjectId bad("not hex");
        (void)bad;
    } catch (const std::invalid_argument&) {
        threw = true;
    }
    CHECK(threw);

    const Commit root(id("a1"), {}, "initial");
    const Commit merge(id("e5"), {id("c3"), id("d4")}, "merge");
    CHECK(root.isRoot() && !root.isMerge());
    CHECK(!merge.isRoot() && merge.isMerge());
    CHECK(merge.parents().size() == 2 && merge.parents()[0] == id("c3"));
    CHECK(merge.message() == "merge");
}

static void testG1AddAndFind() {
    // TODO(G1): paste the starter tests from issue-drafts/10-graph-add-find.md
}

static void testG2FirstParentLog() {
    // TODO(G2): paste the starter tests from issue-drafts/11-graph-first-parent-log.md
}

static void testG3Ancestors() {
    // TODO(G3): paste the starter tests from issue-drafts/12-graph-ancestors.md
}

static void testG4MergeBase() {
    // TODO(G4): paste the starter tests from issue-drafts/13-graph-merge-base.md
}

static void testG5TopologicalOrder() {
    // TODO(G5, stretch): paste the starter tests from issue-drafts/14-graph-topo-order.md
}

int main() {
    testObjectIdAndCommit();
    testG1AddAndFind();
    testG2FirstParentLog();
    testG3Ancestors();
    testG4MergeBase();
    testG5TopologicalOrder();
    return testing::testSummary("commit_graph_tests");
}

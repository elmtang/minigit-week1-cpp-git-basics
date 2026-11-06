# Issue 13 G4 CommitGraph: merge base of two commits

**Class practiced:** `CommitGraph`  
**Function(s):** `mergeBase`

## Goal
Implement `CommitGraph::mergeBase`, the commit Git uses as the starting point of a three-way merge (`git merge-base A B`).

## What you will practice
- combining two algorithms you already wrote
- `std::optional<ObjectId>` as "maybe no answer"

## Dependency
G3 merged.

## Acceptance criteria
- Algorithm from the header comment: `ancestors(a)`, then BFS from `b`, return the first commit found in both.
- Unrelated histories and missing ids return `std::nullopt`.
- Tests pass for both argument orders on the sample graph.
- Copy the starter tests below into `testG4MergeBase()` in `tests/CommitGraphTests.cpp`. Run CTest and see them **fail** before you implement, then make them pass.
- Add at least one test case of your own and explain it in the PR.
- CMake build and CTest pass locally and in Windows/Ubuntu CI.

## Starter tests

```cpp
const CommitGraph g = sampleGraph();
CHECK(g.mergeBase(id("c3"), id("d4")) == id("b2"));
CHECK(g.mergeBase(id("d4"), id("c3")) == id("b2"));
CHECK(g.mergeBase(id("e5"), id("d4")) == id("d4"));
CHECK(g.mergeBase(id("a1"), id("a1")) == id("a1"));
CHECK(!g.mergeBase(id("e5"), id("f6")).has_value()); // unrelated histories
CHECK(!g.mergeBase(id("e5"), id("ff")).has_value()); // missing id
```

## Hints
- Your BFS from G3 is almost what you need; the difference is stopping early.

## Out of scope
Real merging of file contents.

## Evidence to include in the PR
Paste the local CTest output before (failing) and after (passing), name the extra test you added, and report the CI results.

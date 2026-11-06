# Issue 11 G2 CommitGraph: first-parent log

**Class practiced:** `CommitGraph`  
**Function(s):** `firstParentLog`

## Goal
Implement `CommitGraph::firstParentLog`: starting at a commit, follow first parents back to the root, newest first — the history `git log --first-parent` shows.

## What you will practice
- walking a linked structure with a pointer that changes each loop
- why merge commits have an *ordered* list of parents

## Dependency
G1 merged.

## Acceptance criteria
- The result starts with `start` and ends with a root commit.
- Only `parents()[0]` is followed; second parents of merges are skipped.
- A missing `start` returns an empty vector.
- Copy the starter tests below into `testG2FirstParentLog()` in `tests/CommitGraphTests.cpp`. Run CTest and see them **fail** before you implement, then make them pass.
- Add at least one test case of your own and explain it in the PR.
- CMake build and CTest pass locally and in Windows/Ubuntu CI.

## Starter tests

```cpp
const CommitGraph g = sampleGraph();
const std::vector<ObjectId> log = g.firstParentLog(id("e5"));
const std::vector<ObjectId> expected = {id("e5"), id("c3"), id("b2"), id("a1")};
CHECK(log == expected); // d4 is skipped: it is e5's SECOND parent
CHECK(g.firstParentLog(id("a1")) == std::vector<ObjectId>{id("a1")});
CHECK(g.firstParentLog(id("ff")).empty());
```

## Hints
- `const Commit* current = find(start); while (current != nullptr) { ... }`
- Run `git log --first-parent --oneline` in this repository and compare with `git log --oneline --graph`.

## Out of scope
Following every parent (G3).

## Evidence to include in the PR
Paste the local CTest output before (failing) and after (passing), name the extra test you added, and report the CI results.

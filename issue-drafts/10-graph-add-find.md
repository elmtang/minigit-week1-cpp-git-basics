# Issue 10 G1 CommitGraph: add and find commits

**Class practiced:** `CommitGraph (std::map inside a class)`  
**Function(s):** `addCommit / contains / find / size`

## Goal
Implement the G1 member functions in `src/CommitGraph.cpp` so a `CommitGraph` can store commits and look them up.

## What you will practice
- a class that **owns** a collection (`std::map<ObjectId, Commit>`)
- protecting an invariant: every stored commit's parents are stored
- returning `const Commit*` (`nullptr` for not found)

## Dependency
None.

## Acceptance criteria
- `addCommit` returns `false` and changes nothing for a duplicate id or a missing parent.
- `find` returns `nullptr` when missing, otherwise a pointer to the stored commit (not to a copy).
- All lookup functions are `const`.
- Do not change any public signature in `include/CommitGraph.hpp`.
- Copy the starter tests below into `testG1AddAndFind()` in `tests/CommitGraphTests.cpp`. Run CTest and see them **fail** before you implement, then make them pass.
- Add at least one test case of your own and explain it in the PR.
- CMake build and CTest pass locally and in Windows/Ubuntu CI.

## Starter tests

```cpp
CommitGraph g;
CHECK(g.size() == 0);
CHECK(g.addCommit(Commit(id("a1"), {}, "initial")));
CHECK(g.addCommit(Commit(id("b2"), {id("a1")}, "second")));
CHECK(g.size() == 2);
CHECK(g.contains(id("b2")));
CHECK(!g.contains(id("ff")));
CHECK(!g.addCommit(Commit(id("a1"), {}, "duplicate id")));     // duplicate
CHECK(!g.addCommit(Commit(id("c3"), {id("99")}, "orphan")));    // missing parent
CHECK(g.size() == 2);                                           // nothing changed
const Commit* found = g.find(id("b2"));
CHECK(found != nullptr);
CHECK(found != nullptr && found->message() == "second");
CHECK(g.find(id("ff")) == nullptr);
```

## Hints
- `commits_.find(id)` gives an iterator; `it->second` is the `Commit`.
- Check all parents *before* inserting, so a failed call changes nothing.
- Read *The commit graph* in `docs/graph-and-tree-design.md`.

## Out of scope
History traversal (G2–G5).

## Evidence to include in the PR
Paste the local CTest output before (failing) and after (passing), name the extra test you added, and report the CI results.

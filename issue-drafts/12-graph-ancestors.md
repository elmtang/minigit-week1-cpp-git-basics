# Issue 12 G3 CommitGraph: ancestors with breadth-first search

**Class practiced:** `CommitGraph + std::queue + std::set`  
**Function(s):** `ancestors / isAncestor`

## Goal
Implement `CommitGraph::ancestors` with breadth-first search, then `isAncestor` on top of it.

## What you will practice
- BFS on a graph: `std::queue` for the frontier, `std::set` for visited
- why a visited set is needed even though the graph has no cycles (diamond shapes: `b2` is reachable through both `c3` and `d4`)

## Dependency
G1 merged.

## Acceptance criteria
- `ancestors(x)` includes `x` itself and follows **all** parents.
- Each commit is visited once.
- `isAncestor(a, b)` is true when `a` is reachable from `b`; false if either id is missing.
- `isAncestor` reuses `ancestors` instead of duplicating the search.
- Copy the starter tests below into `testG3Ancestors()` in `tests/CommitGraphTests.cpp`. Run CTest and see them **fail** before you implement, then make them pass.
- Add at least one test case of your own and explain it in the PR.
- CMake build and CTest pass locally and in Windows/Ubuntu CI.

## Starter tests

```cpp
const CommitGraph g = sampleGraph();
const std::set<ObjectId> fromMerge = g.ancestors(id("e5"));
CHECK(fromMerge == std::set<ObjectId>({id("a1"), id("b2"), id("c3"), id("d4"), id("e5")}));
CHECK(g.ancestors(id("d4")) == std::set<ObjectId>({id("a1"), id("b2"), id("d4")}));
CHECK(g.ancestors(id("ff")).empty());
CHECK(g.isAncestor(id("a1"), id("e5")));
CHECK(g.isAncestor(id("d4"), id("e5")));
CHECK(g.isAncestor(id("e5"), id("e5")));
CHECK(!g.isAncestor(id("c3"), id("d4"))); // sibling branches
CHECK(!g.isAncestor(id("e5"), id("a1"))); // edges point to the past only
CHECK(!g.isAncestor(id("f6"), id("e5")));
```

## Hints
- Copy the BFS template in `docs/graph-and-tree-design.md`.
- `visited.insert(x).second` is `true` only the first time `x` is inserted.

## Out of scope
Merge base (G4).

## Evidence to include in the PR
Paste the local CTest output before (failing) and after (passing), name the extra test you added, and report the CI results.

# Issue 14 G5 CommitGraph: topological order (stretch)

**Class practiced:** `CommitGraph`  
**Function(s):** `topologicalOrder`

## Goal
Stretch Issue. Implement `CommitGraph::topologicalOrder`: list every commit so that each commit comes before all of its parents, like `git log --topo-order`.

## What you will practice
- Kahn's algorithm
- using a `std::set` as a sorted "ready" list to make output deterministic

## Dependency
G1 merged.

## Acceptance criteria
- Every commit appears exactly once, before each of its parents.
- When several commits are ready, the smallest `ObjectId` goes first (this makes the exact order testable).
- Works with several unrelated roots.
- Copy the starter tests below into `testG5TopologicalOrder()` in `tests/CommitGraphTests.cpp`. Run CTest and see them **fail** before you implement, then make them pass.
- Add at least one test case of your own and explain it in the PR.
- CMake build and CTest pass locally and in Windows/Ubuntu CI.

## Starter tests

```cpp
const CommitGraph g = sampleGraph();
const std::vector<ObjectId> order = g.topologicalOrder();
CHECK(order.size() == g.size());
// Property: every commit appears before each of its parents.
for (std::size_t i = 0; i < order.size(); ++i) {
    const Commit* c = g.find(order[i]);
    CHECK(c != nullptr);
    if (c == nullptr) continue;
    for (const ObjectId& parent : c->parents()) {
        const auto pos = std::find(order.begin(), order.end(), parent);
        CHECK(pos != order.end() && static_cast<std::size_t>(pos - order.begin()) > i);
    }
}
const std::vector<ObjectId> expected = {id("e5"), id("c3"), id("d4"), id("b2"), id("a1"), id("f6")};
CHECK(order == expected); // exact order from the tie-break rule
```

## Hints
- Step 1: count children per commit (`std::map<ObjectId, int>`; every commit starts at 0).
- Step 2: put every commit with 0 children in `ready`.
- Step 3: repeatedly take `*ready.begin()`, output it, and decrement each parent's count; a parent that reaches 0 becomes ready.

## Out of scope
Printing an ASCII graph.

## Evidence to include in the PR
Paste the local CTest output before (failing) and after (passing), name the extra test you added, and report the CI results.

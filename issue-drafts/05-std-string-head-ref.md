# Issue 5 S1 Read the branch name from HEAD text

**Class practiced:** `std::string`  
**Function(s):** `drillBranchFromHead`

## Goal
Implement `drillBranchFromHead` in `src/StdDrills.cpp`. A MiniGit `HEAD` file contains text like `ref: refs/heads/main`; return the branch name.

## What you will practice
- `size()`, `substr()`, `back()`, `pop_back()`, `empty()`
- reusing the worked example `exampleStartsWith`

## Dependency
None.

## Acceptance criteria
- Return the text after `ref: refs/heads/` (branch names may contain `/`, e.g. `feature/login`).
- Remove one trailing `\n`, and a `\r` before it if present.
- Return `""` when the text does not start with the prefix (for example a detached HEAD that holds a commit id).
- Never call `back()` or `pop_back()` on an empty string.
- Copy the starter tests below into `testS1BranchFromHead()` in `tests/StdDrillsTests.cpp`. Run CTest and see them **fail** before you implement, then make them pass.
- Add at least one test case of your own and explain it in the PR.
- CMake build and CTest pass locally and in Windows/Ubuntu CI.

## Starter tests

```cpp
CHECK(drillBranchFromHead("ref: refs/heads/main\n") == "main");
CHECK(drillBranchFromHead("ref: refs/heads/feature/login") == "feature/login");
CHECK(drillBranchFromHead("ref: refs/heads/dev\r\n") == "dev");
CHECK(drillBranchFromHead("a1b2c3d4\n").empty()); // detached HEAD: not a ref
CHECK(drillBranchFromHead("").empty());
```

## Hints
- `std::string prefix = "ref: refs/heads/";` then `headText.substr(prefix.size())`.
- Read the `std::string` section of `docs/std-classes-guide.md`, especially *Common mistakes*.

## Out of scope
Reading the HEAD file from disk (that is S5); validating that the branch exists.

## Evidence to include in the PR
Paste the local CTest output before (failing) and after (passing), name the extra test you added, and report the CI results.

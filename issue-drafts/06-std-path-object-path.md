# Issue 6 S2 Build a Git-style object path

**Class practiced:** `std::filesystem::path`  
**Function(s):** `drillObjectPath`

## Goal
Implement `drillObjectPath` in `src/StdDrills.cpp`. Git stores object `a1b2c3` at `<root>/.minigit/objects/a1/b2c3`: the first two characters of the id become a folder name.

## What you will practice
- `operator/` to join path parts
- `std::string::substr` to split the id
- `filename()` and `parent_path()` (used in the tests)

## Dependency
None.

## Acceptance criteria
- Build the path with `/` on `std::filesystem::path`; no hand-written slash strings.
- The function only builds a path; it creates nothing on disk.
- Tests compare paths, not strings, so they pass on Windows and Ubuntu.
- Copy the starter tests below into `testS2ObjectPath()` in `tests/StdDrillsTests.cpp`. Run CTest and see them **fail** before you implement, then make them pass.
- Add at least one test case of your own and explain it in the PR.
- CMake build and CTest pass locally and in Windows/Ubuntu CI.

## Starter tests

```cpp
const fs::path root = "course/repo";
CHECK(drillObjectPath(root, "a1b2c3") == root / ".minigit" / "objects" / "a1" / "b2c3");
CHECK(drillObjectPath(root, "ffe") == root / ".minigit" / "objects" / "ff" / "e");
CHECK(drillObjectPath(root, "a1b2c3").filename() == "b2c3");
CHECK(drillObjectPath(root, "a1b2c3").parent_path().filename() == "a1");
```

## Hints
- `id.substr(0, 2)` and `id.substr(2)`.
- Compare with `metadataDirectory` in `src/PathLab.cpp`: the same `root / ".minigit"` idea, two levels deeper.

## Out of scope
Hashing file contents; creating the folders.

## Evidence to include in the PR
Paste the local CTest output before (failing) and after (passing), name the extra test you added, and report the CI results.

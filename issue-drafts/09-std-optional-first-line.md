# Issue 9 S5 Read the first line of a file into std::optional

**Class practiced:** `std::optional + std::ifstream`  
**Function(s):** `drillReadFirstLine`

## Goal
Implement `drillReadFirstLine` in `src/StdDrills.cpp`: return the first line of a file, or `std::nullopt` when there is no line to return.

## What you will practice
- `std::ifstream` construction and the `if (!in)` check
- `std::getline` return value
- returning `std::optional<std::string>` / `std::nullopt`

## Dependency
None. Doing S1 first helps.

## Acceptance criteria
- Missing file → `std::nullopt` (no crash, no exception).
- Empty file → `std::nullopt`.
- Remove a trailing `\r` so the result is the same on Windows and Ubuntu.
- The test writes its files in a temporary directory and deletes it at the end.
- Copy the starter tests below into `testS5ReadFirstLine()` in `tests/StdDrillsTests.cpp`. Run CTest and see them **fail** before you implement, then make them pass.
- Add at least one test case of your own and explain it in the PR.
- CMake build and CTest pass locally and in Windows/Ubuntu CI.

## Starter tests

```cpp
const fs::path dir = fs::temp_directory_path() / "minigit-s5-test";
fs::create_directories(dir);
{
    std::ofstream out(dir / "HEAD");
    out << "ref: refs/heads/main\nsecond line\n";
}
{
    std::ofstream out(dir / "empty.txt");
}
CHECK(drillReadFirstLine(dir / "HEAD").value_or("?") == "ref: refs/heads/main");
CHECK(!drillReadFirstLine(dir / "empty.txt").has_value());
CHECK(!drillReadFirstLine(dir / "missing.txt").has_value());
fs::remove_all(dir);
```

## Hints
- Compare with the worked example `exampleReadAll`.
- Combined with S1, `drillBranchFromHead(*drillReadFirstLine(headFile(root)))` is how MiniGit will find the current branch.

## Out of scope
Writing files; reading the whole file.

## Evidence to include in the PR
Paste the local CTest output before (failing) and after (passing), name the extra test you added, and report the CI results.

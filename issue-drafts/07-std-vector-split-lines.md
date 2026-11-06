# Issue 7 S3 Split text into a vector of lines

**Class practiced:** `std::vector + std::istringstream`  
**Function(s):** `drillSplitLines`

## Goal
Implement `drillSplitLines` in `src/StdDrills.cpp`: turn a block of text into a `std::vector<std::string>`, one element per line.

## What you will practice
- `std::vector::push_back`, `size()`, `operator[]`
- `std::istringstream` (include `<sstream>`) as a stream over a string
- `while (std::getline(in, line))`

## Dependency
None.

## Acceptance criteria
- A final line without `\n` still counts.
- An empty string returns an empty vector.
- Blank lines in the middle are kept as empty strings.
- Tests check `size()` before indexing.
- Copy the starter tests below into `testS3SplitLines()` in `tests/StdDrillsTests.cpp`. Run CTest and see them **fail** before you implement, then make them pass.
- Add at least one test case of your own and explain it in the PR.
- CMake build and CTest pass locally and in Windows/Ubuntu CI.

## Starter tests

```cpp
const std::vector<std::string> lines = drillSplitLines("one\ntwo\nthree\n");
CHECK(lines.size() == 3);
CHECK(lines.size() == 3 && lines[0] == "one" && lines[2] == "three");
CHECK(drillSplitLines("no newline").size() == 1);
CHECK(drillSplitLines("").empty());
const std::vector<std::string> withBlank = drillSplitLines("a\n\nb\n");
CHECK(withBlank.size() == 3 && withBlank[1].empty());
```

## Hints
- The same `getline` loop works for files (`std::ifstream`) and strings (`std::istringstream`): both are input streams.

## Out of scope
Handling `\r\n` line endings (optional extra test if you want).

## Evidence to include in the PR
Paste the local CTest output before (failing) and after (passing), name the extra test you added, and report the CI results.

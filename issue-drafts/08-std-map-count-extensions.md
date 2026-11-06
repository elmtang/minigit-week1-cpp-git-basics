# Issue 8 S4 Count files by extension with std::map

**Class practiced:** `std::map`  
**Function(s):** `drillCountExtensions`

## Goal
Implement `drillCountExtensions` in `src/StdDrills.cpp`: return how many files have each extension.

## What you will practice
- `std::map` `operator[]`, `count()`, `at()`, `size()`
- `path::extension()` and converting it with `.string()`

## Dependency
None.

## Acceptance criteria
- Keys include the dot: `.cpp`, `.hpp`.
- Files with no extension are counted under `(none)`.
- An empty input gives an empty map.
- Copy the starter tests below into `testS4CountExtensions()` in `tests/StdDrillsTests.cpp`. Run CTest and see them **fail** before you implement, then make them pass.
- Add at least one test case of your own and explain it in the PR.
- CMake build and CTest pass locally and in Windows/Ubuntu CI.

## Starter tests

```cpp
const std::map<std::string, int> counts =
    drillCountExtensions({"a.cpp", "src/b.cpp", "c.hpp", "README", "LICENSE"});
CHECK(counts.size() == 3);
CHECK(counts.count(".cpp") == 1 && counts.at(".cpp") == 2);
CHECK(counts.count(".hpp") == 1 && counts.at(".hpp") == 1);
CHECK(counts.count("(none)") == 1 && counts.at("(none)") == 2);
CHECK(drillCountExtensions({}).empty());
```

## Hints
- Look at the worked example `exampleWordCount`; this drill is the same pattern plus one `if`.
- Why do the tests call `count(key)` before `at(key)`? (See *Common mistakes* for `std::map`.)

## Out of scope
Sorting by count; case-insensitive extensions.

## Evidence to include in the PR
Paste the local CTest output before (failing) and after (passing), name the extra test you added, and report the CI results.

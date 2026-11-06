# Issue 15 G6 FileTree: add files and look them up

**Class practiced:** `FileTree (recursive nodes, std::unique_ptr)`  
**Function(s):** `addFile / containsFile / blobOf`

## Goal
Implement the G6 member functions in `src/FileTree.cpp` so files can be added at nested paths and found again.

## What you will practice
- iterating a `std::filesystem::path` part by part
- creating owned child nodes with `std::make_unique<Node>()`
- walking down a tree with a `Node*` / `const Node*`

## Dependency
None (independent of G1–G5).

## Acceptance criteria
- Missing directories are created on the way down.
- Adding an existing file replaces its blob id.
- Rejected (return `false`, tree unchanged): empty path, absolute path, a `.` or `..` part, a file where a directory is needed, a directory where the file should go.
- `containsFile` is true only for files; `blobOf` returns `std::nullopt` for directories and missing paths.
- Copy the starter tests below into `testG6AddAndLookup()` in `tests/FileTreeTests.cpp`. Run CTest and see them **fail** before you implement, then make them pass.
- Add at least one test case of your own and explain it in the PR.
- CMake build and CTest pass locally and in Windows/Ubuntu CI.

## Starter tests

```cpp
FileTree t;
CHECK(t.addFile("README.md", id("aa")));
CHECK(t.addFile("src/util/math.cpp", id("cc"))); // creates src/ and src/util/
CHECK(t.containsFile("README.md"));
CHECK(t.containsFile("src/util/math.cpp"));
CHECK(!t.containsFile("src"));          // a directory is not a file
CHECK(!t.containsFile("src/missing.cpp"));
CHECK(t.blobOf("src/util/math.cpp") == id("cc"));
CHECK(!t.blobOf("src/util").has_value());
CHECK(t.addFile("README.md", id("ab")));  // replacing a file is allowed
CHECK(t.blobOf("README.md") == id("ab"));
// Rejected paths
CHECK(!t.addFile("", id("aa")));
CHECK(!t.addFile("../outside.txt", id("aa")));
CHECK(!t.addFile("README.md/inner.txt", id("aa"))); // README.md is a file
CHECK(!t.addFile("src", id("aa")));                 // src is a directory
CHECK(!t.containsFile("README.md/inner.txt"));
```

## Hints
- `for (const auto& part : relativePath)` gives each name as a `path`; use `part.string()` as the map key.
- Check for conflicts before creating anything, so a rejected call leaves the tree unchanged.
- A private helper that finds a node by path (declared in the private section of the header) keeps `containsFile` and `blobOf` short.

## Out of scope
Removing files; reading from disk.

## Evidence to include in the PR
Paste the local CTest output before (failing) and after (passing), name the extra test you added, and report the CI results.

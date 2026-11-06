# Issue 18 G9 FileTree: diff two snapshots

**Class practiced:** `FileTree + TreeDiff`  
**Function(s):** `diff`

## Goal
Implement `FileTree::diff`: compare this (older) tree with a newer one and report added, removed, and modified files (like `git diff --name-status`).

## What you will practice
- reusing your own public functions (`listFiles`, `blobOf`, `containsFile`) to build a bigger feature
- returning a small result struct (`TreeDiff`)

## Dependency
G7 merged.

## Acceptance criteria
- A file only in the newer tree is *added*; only in the older tree is *removed*; in both with different blob ids is *modified*.
- Each list is sorted.
- Comparing a tree with an identical tree gives three empty lists.
- Copy the starter tests below into `testG9Diff()` in `tests/FileTreeTests.cpp`. Run CTest and see them **fail** before you implement, then make them pass.
- Add at least one test case of your own and explain it in the PR.
- CMake build and CTest pass locally and in Windows/Ubuntu CI.

## Starter tests

```cpp
const FileTree older = sampleTree();
FileTree newer;
newer.addFile("README.md", id("aa"));          // unchanged
newer.addFile("src/main.cpp", id("b0"));       // modified
newer.addFile("src/util/strings.cpp", id("dd")); // added
newer.addFile("docs/guide.md", id("ee"));      // added
// src/util/math.cpp removed
const TreeDiff d = older.diff(newer);
CHECK(d.added == std::vector<std::string>({"docs/guide.md", "src/util/strings.cpp"}));
CHECK(d.removed == std::vector<std::string>({"src/util/math.cpp"}));
CHECK(d.modified == std::vector<std::string>({"src/main.cpp"}));

const TreeDiff same = older.diff(sampleTree());
CHECK(same.added.empty() && same.removed.empty() && same.modified.empty());
```

## Hints
- Loop over `listFiles()` of the older tree, then of the newer tree.
- `std::sort` from `<algorithm>`.

## Out of scope
Line-by-line content diff; rename detection.

## Evidence to include in the PR
Paste the local CTest output before (failing) and after (passing), name the extra test you added, and report the CI results.

# Issue 16 G7 FileTree: count and list files recursively

**Class practiced:** `FileTree`  
**Function(s):** `fileCount / listFiles`

## Goal
Implement `FileTree::fileCount` and `FileTree::listFiles` with recursion (like `git ls-tree -r --name-only`).

## What you will practice
- recursive functions on a tree
- depth-first preorder traversal
- building paths as strings with `/` for output

## Dependency
G6 merged.

## Acceptance criteria
- `fileCount` counts files only, not directories.
- `listFiles` returns generic paths (`src/util/math.cpp`) in depth-first order, children in name order.
- Both are `const` and do not modify the tree.
- Copy the starter tests below into `testG7CountAndList()` in `tests/FileTreeTests.cpp`. Run CTest and see them **fail** before you implement, then make them pass.
- Add at least one test case of your own and explain it in the PR.
- CMake build and CTest pass locally and in Windows/Ubuntu CI.

## Starter tests

```cpp
const FileTree t = sampleTree();
CHECK(t.fileCount() == 3);
const std::vector<std::string> expected = {"README.md", "src/main.cpp", "src/util/math.cpp"};
CHECK(t.listFiles() == expected);
```

## Hints
- A recursive helper such as `static void collectFiles(const Node& node, const std::string& prefix, std::vector<std::string>& out);` in the private section of `FileTree.hpp`.
- `std::map` already iterates in sorted name order.

## Out of scope
Rendering (G8).

## Evidence to include in the PR
Paste the local CTest output before (failing) and after (passing), name the extra test you added, and report the CI results.

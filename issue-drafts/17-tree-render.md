# Issue 17 G8 FileTree: render the tree as text

**Class practiced:** `FileTree`  
**Function(s):** `render`

## Goal
Implement `FileTree::render` to draw the tree like the `tree` command (ASCII characters so it prints the same on Windows and Ubuntu).

## What you will practice
- passing state (the indentation string) down a recursion
- detecting the last child in a `std::map` loop

## Dependency
G6 merged.

## Acceptance criteria
- First line is `.`; every line ends with `\n`.
- An entry line is `indent + "|-- " + name`, or `indent + "`-- " + name` for the last child.
- Children of an entry are indented with `"|   "` (not last) or `"    "` (last).
- Output matches the expected strings in the tests exactly.
- Copy the starter tests below into `testG8Render()` in `tests/FileTreeTests.cpp`. Run CTest and see them **fail** before you implement, then make them pass.
- Add at least one test case of your own and explain it in the PR.
- CMake build and CTest pass locally and in Windows/Ubuntu CI.

## Starter tests

```cpp
const FileTree t = sampleTree();
const std::string expected =
    ".\n"
    "|-- README.md\n"
    "`-- src\n"
    "    |-- main.cpp\n"
    "    `-- util\n"
    "        `-- math.cpp\n";
CHECK(t.render() == expected);

FileTree two;
two.addFile("a/x.txt", id("01"));
two.addFile("b.txt", id("02"));
const std::string expectedTwo =
    ".\n"
    "|-- a\n"
    "|   `-- x.txt\n"
    "`-- b.txt\n";
CHECK(two.render() == expectedTwo);
```

## Hints
- Count children as you loop: `bool last = (++index == node.children.size());`
- Print the result in a scratch `main` to compare with the expected text visually.

## Out of scope
Showing blob ids in the drawing.

## Evidence to include in the PR
Paste the local CTest output before (failing) and after (passing), name the extra test you added, and report the CI results.

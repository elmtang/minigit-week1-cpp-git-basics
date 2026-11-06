# Standard-Library Classes Used in MiniGit

MiniGit leans on a handful of classes that come with C++17. You did not write them, but you need to *use* them fluently: create them, call their member functions, and recognize their common mistakes. This guide covers each one with the same four questions:

1. **What is it?** — the one-sentence mental model.
2. **Members you will actually use** — a short list, not the whole reference.
3. **In MiniGit** — where it appears in this repository.
4. **Common mistakes** — what students usually get wrong.

Each class has a worked example in `src/StdDrills.cpp` (functions named `example*`) and one practice drill (functions named `drill*`, Issues **S1–S5** in `issue-drafts/`).

| Class | Header | Worked example | Drill |
|---|---|---|---|
| `std::string` | `<string>` | `exampleStartsWith` | S1 `drillBranchFromHead` |
| `std::filesystem::path` | `<filesystem>` | `exampleStem` | S2 `drillObjectPath` |
| `std::vector` | `<vector>` | `exampleFilterByExtension` | S3 `drillSplitLines` |
| `std::map` | `<map>` | `exampleWordCount` | S4 `drillCountExtensions` |
| `std::optional`, `std::ifstream` | `<optional>`, `<fstream>` | `exampleReadAll` | S5 `drillReadFirstLine` |

---

## How to read a reference page

Use [cppreference.com](https://en.cppreference.com/). For any class, look for three things in this order:

1. **The header** at the top (for example `Defined in header <filesystem>`). Add that `#include`.
2. **Member functions** table. Read the one-line description of each; ignore anything marked C++20 or later (we use C++17).
3. **The example** at the bottom of a member-function page. Copy it into a scratch file and run it before using the function in MiniGit.

A member function is called on an object: `text.size()`. A non-member (free) function takes the object as an argument: `std::getline(in, line)`. Reference pages list both; check which one you are reading.

---

## `std::string` — a resizable sequence of characters

**Members you will use**

| Member | Meaning |
|---|---|
| `size()`, `empty()` | number of characters; true if size is 0 |
| `s[i]`, `back()` | character at index `i`; last character (only if not empty!) |
| `substr(pos, count)` | copy of `count` characters starting at `pos` (count defaults to "the rest") |
| `find(x)`, `rfind(x)` | index of the first/last match, or `std::string::npos` if none |
| `compare(pos, count, other)` | 0 if that part equals `other` |
| `push_back(c)`, `pop_back()`, `+=` | add/remove at the end |

**In MiniGit** — file contents (`HEAD`, commit messages), branch names, object ids.

**Common mistakes**

- Calling `back()` or `pop_back()` on an empty string: undefined behavior. Check `empty()` first.
- Comparing `find(...)` with `-1` or `0` instead of `std::string::npos`.
- `substr(pos)` throws `std::out_of_range` if `pos > size()`.

```cpp
std::string head = "ref: refs/heads/main\n";
std::size_t slash = head.rfind('/');          // index of the last '/'
std::string branch = head.substr(slash + 1);  // "main\n"
if (!branch.empty() && branch.back() == '\n') branch.pop_back();
```

---

## `std::filesystem::path` — a file or folder *name*, not a file

A `path` is just a structured name. Creating one never touches the disk. Functions such as `std::filesystem::exists` or `create_directories` are the ones that touch the disk.

**Members you will use**

| Member | `"course/repo/src/PathLab.cpp"` gives |
|---|---|
| `p / "x"` | joins with the correct separator: `course/repo/src/PathLab.cpp/x` |
| `parent_path()` | `course/repo/src` |
| `filename()` | `PathLab.cpp` |
| `stem()` | `PathLab` |
| `extension()` | `.cpp` (with the dot; empty path if none) |
| `string()`, `generic_string()` | text; `generic_string()` always uses `/` (good for tests and output) |
| `for (const auto& part : p)` | iterates `course`, `repo`, `src`, `PathLab.cpp` |
| `lexically_relative(base)` | path of `p` relative to `base` |
| `is_absolute()`, `has_root_path()` | starts at a drive/root? |

**In MiniGit** — `PathLab.cpp` builds `.minigit/HEAD`; S2 builds object paths; `FileTree` iterates path parts.

**Common mistakes**

- Building paths with `+ "/" +` strings. Use `/`; it is correct on Windows and Linux.
- Comparing `p.string() == "a/b"`: fails on Windows (`a\b`). Compare paths (`p == fs::path("a") / "b"`) or use `generic_string()`.
- Forgetting that `extension()` returns a `path`. It compares fine with a string literal, but call `.string()` before using it as a `std::string` (for example as a map key).

---

## `std::vector<T>` — a resizable array that owns its elements

**Members you will use**: `push_back(x)`, `size()`, `empty()`, `v[i]`, `front()`, `back()`, range-for (`for (const T& x : v)`), `==` (same size and same elements in order).

**In MiniGit** — commit parents (`std::vector<ObjectId>`), lists of files, lines of a text file.

**Common mistakes**

- `v[i]` with `i >= size()` is undefined behavior. Check the size first (tests do this: `CHECK(v.size() == 3 && v[2] == ...)`).
- Writing `for (T x : v)` copies every element. Use `const T&` unless you need a copy.
- Keeping a pointer or reference into a vector and then calling `push_back`: the vector may reallocate and the pointer dangles.

---

## `std::map<Key, Value>` — sorted key → value table

**Members you will use**

| Member | Meaning |
|---|---|
| `m[key]` | value for key; **inserts a default value if missing** |
| `m.at(key)` | value for key; throws if missing |
| `m.count(key)` | 1 if present, 0 if not |
| `m.find(key)` | iterator; equals `m.end()` if missing; `it->first` is the key, `it->second` the value |
| `m.emplace(key, value)` | insert if missing; returns `{iterator, bool inserted}` |
| range-for | visits entries in **sorted key order**: `for (const auto& [key, value] : m)` |

**In MiniGit** — `CommitGraph` stores `std::map<ObjectId, Commit>`; `FileTree` stores each directory's children in a map so listings come out sorted. `std::set<T>` is the same idea with keys only.

**Common mistakes**

- Using `m[key]` just to *check* whether a key exists: it silently inserts. Use `count` or `find`.
- `operator[]` does not work on a `const` map. Use `find` or `at`.
- Keys need `operator<`. That is why `ObjectId` defines one.

---

## `std::optional<T>` and `std::ifstream` — "maybe a value" and reading files

`std::optional<T>` holds either a `T` or nothing (`std::nullopt`). Use it as a return type when "no answer" is a normal outcome, not an error.

| `std::optional<T>` | Meaning |
|---|---|
| `return value;` / `return std::nullopt;` | with / without a value |
| `has_value()` or `if (opt)` | is there a value? |
| `*opt`, `opt.value()` | the value (`value()` throws if empty) |
| `opt.value_or(fallback)` | the value, or `fallback` |

`std::ifstream in(path);` opens a file for reading. `if (!in)` means it failed to open. Read with `std::getline(in, line)` (one line, returns false at end of file) or `buffer << in.rdbuf()` (everything). `std::ofstream` is the writing counterpart; it closes the file when it goes out of scope.

**In MiniGit** — `readText`-style helpers (Issue 4), `FileTree::blobOf`, `CommitGraph::mergeBase`.

**Common mistakes**

- Using `*opt` without checking `has_value()`.
- Reading a file before the `ofstream` that wrote it has closed. Put the writer in its own `{ }` block (see `tests/StdDrillsTests.cpp`).
- On Windows text files may end lines with `\r\n`. If a line might end with `'\r'`, remove it.

---

## Check yourself (discuss in your team before S1)

1. Which of these touch the disk: `fs::path p = "a/b";`, `p.parent_path()`, `fs::exists(p)`, `fs::create_directories(p)`?
2. Why does `std::map<std::string, int> m; if (m["x"] == 0) {}` leave `m.size() == 1`?
3. What does `fs::path("a.tar.gz").extension()` return? And `stem()`?
4. `std::vector<int> v; v.back();` — what happens?
5. When should a function return `std::optional<T>` instead of throwing an exception?

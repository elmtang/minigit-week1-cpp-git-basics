# MiniGit Week 1 TODO

Use this list to choose a small practice task. A checkbox is only a Markdown checklist item; it does not create a GitHub Issue. Create an Issue from the corresponding draft in `issue-drafts/`, then replace the draft reference below with the actual `#number` link.

- [ ] **F2.1a — Metadata directory path** — Return `root / ".minigit"`; add ordinary and nested path tests. Draft: [`issue-drafts/01-metadata-directory.md`](issue-drafts/01-metadata-directory.md).
- [ ] **F2.1b — HEAD file path** — Reuse the metadata path helper and append `HEAD`; add ordinary and nested path tests. Draft: [`issue-drafts/02-head-path.md`](issue-drafts/02-head-path.md).
- [ ] **F2.2a — Write a text file** — Create missing parent folders, write text, and report failure; test and clean up a temporary test directory. Draft: [`issue-drafts/03-write-text.md`](issue-drafts/03-write-text.md).
- [ ] **F2.2b — Read a text file** — Read back exact contents and report a missing file; test and clean up temporary files. Draft: [`issue-drafts/04-read-text.md`](issue-drafts/04-read-text.md).

## Standard-library class drills

Read [`docs/std-classes-guide.md`](docs/std-classes-guide.md) first. Code: `include/StdDrills.hpp`, `src/StdDrills.cpp`, tests in `tests/StdDrillsTests.cpp`.

- [ ] **S1 — `std::string`: branch name from HEAD** — Draft: [`issue-drafts/05-std-string-head-ref.md`](issue-drafts/05-std-string-head-ref.md).
- [ ] **S2 — `std::filesystem::path`: object path** — Draft: [`issue-drafts/06-std-path-object-path.md`](issue-drafts/06-std-path-object-path.md).
- [ ] **S3 — `std::vector`: split lines** — Draft: [`issue-drafts/07-std-vector-split-lines.md`](issue-drafts/07-std-vector-split-lines.md).
- [ ] **S4 — `std::map`: count extensions** — Draft: [`issue-drafts/08-std-map-count-extensions.md`](issue-drafts/08-std-map-count-extensions.md).
- [ ] **S5 — `std::optional` + `std::ifstream`: first line of a file** — Draft: [`issue-drafts/09-std-optional-first-line.md`](issue-drafts/09-std-optional-first-line.md).

## Commit graph and file tree (our own classes)

Read [`docs/graph-and-tree-design.md`](docs/graph-and-tree-design.md) first. `ObjectId` and `Commit` are provided; you implement `CommitGraph` and `FileTree`.

- [ ] **G1 — CommitGraph add / find** — [`issue-drafts/10-graph-add-find.md`](issue-drafts/10-graph-add-find.md)
- [ ] **G2 — first-parent log** (after G1) — [`issue-drafts/11-graph-first-parent-log.md`](issue-drafts/11-graph-first-parent-log.md)
- [ ] **G3 — ancestors with BFS** (after G1) — [`issue-drafts/12-graph-ancestors.md`](issue-drafts/12-graph-ancestors.md)
- [ ] **G4 — merge base** (after G3) — [`issue-drafts/13-graph-merge-base.md`](issue-drafts/13-graph-merge-base.md)
- [ ] **G5 — topological order, stretch** (after G1) — [`issue-drafts/14-graph-topo-order.md`](issue-drafts/14-graph-topo-order.md)
- [ ] **G6 — FileTree add / look up** — [`issue-drafts/15-tree-add-lookup.md`](issue-drafts/15-tree-add-lookup.md)
- [ ] **G7 — count and list files** (after G6) — [`issue-drafts/16-tree-count-list.md`](issue-drafts/16-tree-count-list.md)
- [ ] **G8 — render as text** (after G6) — [`issue-drafts/17-tree-render.md`](issue-drafts/17-tree-render.md)
- [ ] **G9 — diff two trees** (after G7) — [`issue-drafts/18-tree-diff.md`](issue-drafts/18-tree-diff.md)

## Classroom demonstration checklist

- [ ] Turn one TODO item into a well-scoped GitHub Issue.
- [ ] Create a feature branch from `main` in GitHub Desktop or VS Code.
- [ ] Make one small code-and-test change.
- [ ] Configure, build, and test locally with CMake/CTest.
- [ ] Commit and push the feature branch.
- [ ] Open a PR linked to its Issue and inspect GitHub Actions.
- [ ] Have a second collaborator review and approve the PR.
- [ ] Merge using the method selected by the instructor.
- [ ] Confirm the commit appears on `main`, the PR is closed, and the Issue closes when the PR targets the default branch and uses `Closes #number`.

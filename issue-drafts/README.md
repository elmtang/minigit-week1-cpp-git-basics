# GitHub Issue drafts

These drafts are intended for instructor publication as GitHub Issues.

## Week 1: paths and text files
Suggested sequence: Issue 1 → Issue 2 → Issue 3 → Issue 4. Publish only the first Issue during the first lab; release later Issues as students learn the workflow.

## Standard-library class drills (S1–S5)
Guide: [`docs/std-classes-guide.md`](../docs/std-classes-guide.md). Each drill practices one standard-library class and is independent of the others, so team members can take different drills and review each other's PRs.

| Draft | Class |
|---|---|
| [05 S1 branch name from HEAD](05-std-string-head-ref.md) | `std::string` |
| [06 S2 object path](06-std-path-object-path.md) | `std::filesystem::path` |
| [07 S3 split lines](07-std-vector-split-lines.md) | `std::vector`, `std::istringstream` |
| [08 S4 count extensions](08-std-map-count-extensions.md) | `std::map` |
| [09 S5 first line of a file](09-std-optional-first-line.md) | `std::optional`, `std::ifstream` |

## Our own classes: commit graph and file tree (G1–G9)
Design: [`docs/graph-and-tree-design.md`](../docs/graph-and-tree-design.md). The graph track (G1–G5) and the tree track (G6–G9) are independent of each other.

| Draft | Depends on |
|---|---|
| [10 G1 add / find commits](10-graph-add-find.md) | — |
| [11 G2 first-parent log](11-graph-first-parent-log.md) | G1 |
| [12 G3 ancestors (BFS)](12-graph-ancestors.md) | G1 |
| [13 G4 merge base](13-graph-merge-base.md) | G3 |
| [14 G5 topological order (stretch)](14-graph-topo-order.md) | G1 |
| [15 G6 add / look up files](15-tree-add-lookup.md) | — |
| [16 G7 count and list files](16-tree-count-list.md) | G6 |
| [17 G8 render as text](17-tree-render.md) | G6 |
| [18 G9 diff two trees](18-tree-diff.md) | G7 |

Every S/G draft includes starter tests. Students paste them into the matching empty test function, see them fail, implement, and see them pass.

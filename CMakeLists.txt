cmake_minimum_required(VERSION 3.20)
project(MiniGitWeek1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Week 1: path helpers (std::filesystem::path)
add_library(minigit_paths src/PathLab.cpp)
target_include_directories(minigit_paths PUBLIC include)

# Standard-library class drills (docs/std-classes-guide.md, Issues S1-S5)
add_library(minigit_drills src/StdDrills.cpp)
target_include_directories(minigit_drills PUBLIC include)

# Our own classes: commit graph and file tree (docs/graph-and-tree-design.md, Issues G1-G9)
add_library(minigit_core
    src/ObjectId.cpp
    src/Commit.cpp
    src/CommitGraph.cpp
    src/FileTree.cpp)
target_include_directories(minigit_core PUBLIC include)

include(CTest)
if(BUILD_TESTING)
    add_executable(path_lab_tests tests/PathLabTests.cpp)
    target_link_libraries(path_lab_tests PRIVATE minigit_paths)
    add_test(NAME path_lab_tests COMMAND path_lab_tests)

    add_executable(std_drills_tests tests/StdDrillsTests.cpp)
    target_link_libraries(std_drills_tests PRIVATE minigit_drills)
    add_test(NAME std_drills_tests COMMAND std_drills_tests)

    add_executable(commit_graph_tests tests/CommitGraphTests.cpp)
    target_link_libraries(commit_graph_tests PRIVATE minigit_core)
    add_test(NAME commit_graph_tests COMMAND commit_graph_tests)

    add_executable(file_tree_tests tests/FileTreeTests.cpp)
    target_link_libraries(file_tree_tests PRIVATE minigit_core)
    add_test(NAME file_tree_tests COMMAND file_tree_tests)
endif()

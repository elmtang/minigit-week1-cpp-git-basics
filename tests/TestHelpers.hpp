#pragma once
// Tiny test helper shared by the test programs.
//
//   CHECK(condition) records a failure (with file and line) but keeps going,
//   so one run shows every broken test. Finish main() with
//   `return testSummary("name");` which prints a summary and returns 1 if
//   anything failed (CTest treats a non-zero exit code as a failure).

#include <iostream>

namespace testing {

inline int& failureCount() {
    static int count = 0;
    return count;
}

inline void recordCheck(bool ok, const char* expression, const char* file, int line) {
    if (!ok) {
        ++failureCount();
        std::cerr << file << ':' << line << ": FAILED: " << expression << '\n';
    }
}

inline int testSummary(const char* suiteName) {
    if (failureCount() == 0) {
        std::cout << suiteName << ": all checks passed\n";
        return 0;
    }
    std::cerr << suiteName << ": " << failureCount() << " check(s) failed\n";
    return 1;
}

} // namespace testing

#define CHECK(condition) ::testing::recordCheck(static_cast<bool>(condition), #condition, __FILE__, __LINE__)

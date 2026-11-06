#pragma once
// ObjectId: a small VALUE class that names a commit, tree, or file blob.
//
// Real Git uses a 40-character SHA-1 hex string. MiniGit accepts any
// non-empty string of lowercase hex digits so tests can use short ids
// such as "a1" or "c0ffee".
//
// Design lessons in this class (read before writing your own classes):
//   * The constructor checks the invariant once ("always valid hex"), so no
//     other code has to re-check it.
//   * The data member is private; callers use text() and shortText().
//   * operator== and operator< make ObjectId usable as a std::map / std::set
//     key, just like std::string.

#include <iosfwd>
#include <string>

namespace minigit {

class ObjectId {
public:
    // Throws std::invalid_argument if text is empty or not lowercase hex.
    explicit ObjectId(std::string text);

    const std::string& text() const { return text_; }

    // First 7 characters (or the whole id if shorter), like `git log --oneline`.
    std::string shortText() const;

    static bool isValidText(const std::string& text);

    friend bool operator==(const ObjectId& a, const ObjectId& b) { return a.text_ == b.text_; }
    friend bool operator!=(const ObjectId& a, const ObjectId& b) { return !(a == b); }
    friend bool operator<(const ObjectId& a, const ObjectId& b) { return a.text_ < b.text_; }

private:
    std::string text_;
};

std::ostream& operator<<(std::ostream& out, const ObjectId& id);

} // namespace minigit

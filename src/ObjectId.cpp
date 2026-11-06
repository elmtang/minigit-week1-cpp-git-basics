#include "ObjectId.hpp"

#include <ostream>
#include <stdexcept>
#include <utility>

namespace minigit {

ObjectId::ObjectId(std::string text) : text_(std::move(text)) {
    if (!isValidText(text_)) {
        throw std::invalid_argument("ObjectId must be non-empty lowercase hex: '" + text_ + "'");
    }
}

std::string ObjectId::shortText() const {
    return text_.substr(0, 7); // substr stops early if the string is shorter
}

bool ObjectId::isValidText(const std::string& text) {
    if (text.empty()) {
        return false;
    }
    for (char c : text) {
        const bool digit = c >= '0' && c <= '9';
        const bool lowerHex = c >= 'a' && c <= 'f';
        if (!digit && !lowerHex) {
            return false;
        }
    }
    return true;
}

std::ostream& operator<<(std::ostream& out, const ObjectId& id) {
    return out << id.text();
}

} // namespace minigit

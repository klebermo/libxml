#include "string.hpp"

std::ostream& String::print(std::ostream& os) {
    os << str();
    return os;
}

std::istream& String::read(std::istream& is) {
    is >> value;
    return is;
}

std::string String::str() {
    return value;
}

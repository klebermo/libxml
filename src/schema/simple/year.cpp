#include "year.hpp"

std::ostream& Year::print(std::ostream& os) {
    os << str();
    return os;
}

std::istream& Year::read(std::istream& is) {
    is >> value;
    return is;
}

std::string Year::str() {
    return std::string(value);
}

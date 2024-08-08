#include "duration.hpp"

std::ostream& Duration::print(std::ostream& os) {
    os << str();
    return os;
}

std::istream& Duration::read(std::istream& is) {
    is >> value;
    return is;
}

std::string Duration::str() {
    return std::to_string(value);
}

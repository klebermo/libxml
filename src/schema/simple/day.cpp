#include "day.hpp"

std::ostream& Day::print(std::ostream& os) {
    os << str();
    return os;
}

std::istream& Day::read(std::istream& is) {
    is >> value;
    return is;
}

std::string Day::str() {
    return std::string(value);
}

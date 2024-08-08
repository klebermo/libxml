#include "month.hpp"

std::ostream& Month::print(std::ostream& os) {
    os << str();
    return os;
}

std::istream& Month::read(std::istream& is) {
    is >> value;
    return is;
}

std::string Month::str() {
    return std::string(value);
}

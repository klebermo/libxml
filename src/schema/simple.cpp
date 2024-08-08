#include "simple.hpp"

std::ostream& operator<<(std::ostream& os, simpleType& type) {
    return type.print(os);
}

std::istream& operator>>(std::istream& is, simpleType& type) {
    return type.read(is);
}

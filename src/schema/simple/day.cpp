#include "day.hpp"

std::string Day::print() {
    return std::string(value);
}

void Day::read(std::string data) {
    std::stringstream is(data);
    is >> value;
}

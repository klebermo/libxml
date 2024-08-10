#include "month.hpp"

std::string Month::print() {
    return std::string(value);
}

void Month::read(std::string data) {
    std::stringstream is(data);
    is >> value;
}

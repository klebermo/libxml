#include "year.hpp"

std::string Year::print() {
    return std::string(value);
}

void Year::read(std::string data) {
    std::stringstream is(data);
    is >> value;
}

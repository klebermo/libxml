#include "duration.hpp"

std::string Duration::print() {
    return std::to_string(value);
}

void Duration::read(std::string data) {
    std::stringstream is(data);
    is >> value;
}

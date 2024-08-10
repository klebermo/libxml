#include "year_month.hpp"

std::string YearMonth::print() {
    return std::string(value);
}

void YearMonth::read(std::string data) {
    char year[5], month[3], slash;
    std::stringstream is(data);
    is.read(month, 2);
    is.read(&slash, 1);
    is.read(year, 4);

    if(slash == '/' && is) {
        value[0] = month[0];
        value[1] = month[1];
        value[2] = year[0];
        value[3] = year[1];
        value[4] = year[2];
        value[5] = year[3];
    }
}

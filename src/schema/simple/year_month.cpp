#include "year_month.hpp"

std::ostream& YearMonth::print(std::ostream& os) {
    os << str();
    return os;
}

std::istream& YearMonth::read(std::istream& is) {
    char year[5], month[3], slash;
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
    } else {
        is.setstate(std::ios::failbit);
    }
    return is;
}

std::string YearMonth::str() {
    return std::string(value);
}

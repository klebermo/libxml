#include "month_day.hpp"

std::ostream& MonthDay::print(std::ostream& os) {
    os << str();
    return os;
}

std::istream& MonthDay::read(std::istream& is) {
    char day[3], month[3], slash;
    is.read(day, 2);
    is.read(&slash, 1);
    is.read(month, 2);

    if(slash == '/' && is) {
        value[0] = day[0];
        value[1] = day[1];
        value[2] = month[0];
        value[3] = month[1];
    } else {
        is.setstate(std::ios::failbit);
    }
    return is;
}

std::string MonthDay::str() {
    return std::string(value);
}

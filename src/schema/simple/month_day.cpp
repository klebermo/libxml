#include "month_day.hpp"

std::string MonthDay::print() {
    return std::string(value);
}

void MonthDay::read(std::string data) {
    char day[3], month[3], slash;
    std::stringstream is(data);
    is.read(day, 2);
    is.read(&slash, 1);
    is.read(month, 2);

    if(slash == '/' && is) {
        value[0] = day[0];
        value[1] = day[1];
        value[2] = month[0];
        value[3] = month[1];
    }
}

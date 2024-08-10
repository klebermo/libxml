#include "date.hpp"

std::string Date::print() {
    u_int8_t year1 = (year() >> 8) & 0xFF;
    u_int8_t year2 = year() & 0xFF;

    u_int8_t data[] = {day(), '/', month(), '/', year1, year2};
    size_t arraySize = sizeof(data) / sizeof(data[0]);

    std::string result(reinterpret_cast<const char*>(data), arraySize);
    return result;
}

void Date::read(std::string data) {
    value = 0;
    int d, m, y;
    char slash1, slash2;
    
    std::stringstream is(data);
    if (is >> d >> slash1 >> m >> slash2 >> y) {
        if (slash1 == '/' && slash2 == '/') {
            value = 0;
            value |= static_cast<u_int64_t>(d);
            value |= static_cast<u_int64_t>(m) << 6;
            value |= static_cast<u_int64_t>(y) << 12;
        }
    }
}

u_int8_t Date::day() {
    return value & 0x1F;
}

u_int8_t Date::month() {
    return (value >> 5) & 0x0F;
}

u_int16_t Date::year() {
    return (value >> 9) & 0xFFF;
}

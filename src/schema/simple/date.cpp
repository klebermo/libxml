#include "date.hpp"

std::ostream& Date::print(std::ostream& os) {
    os << str();
    return os;
}

std::istream& Date::read(std::istream& is) {
    int d, m, y;
    char slash1, slash2;
    
    if (is >> d >> slash1 >> m >> slash2 >> y) {
        if (slash1 == '/' && slash2 == '/') {
            value = 0;
            value |= static_cast<u_int64_t>(d);
            value |= static_cast<u_int64_t>(m) << 6;
            value |= static_cast<u_int64_t>(y) << 12;
        } else {
            is.setstate(std::ios::failbit);
        }
    } else {
        is.setstate(std::ios::failbit);
    }

    return is;
}

std::string Date::str() {
    u_int8_t year1 = (year() >> 8) & 0xFF;
    u_int8_t year2 = year() & 0xFF;

    u_int8_t data[] = {day(), '/', month(), '/', year1, year2};
    size_t arraySize = sizeof(data) / sizeof(data[0]);

    std::string result(reinterpret_cast<const char*>(data), arraySize);
    return result;
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

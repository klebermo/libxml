#include "date_time.hpp"

std::ostream& Datetime::print(std::ostream& os) {
    os << str();
    return os;
}

std::istream& Datetime::read(std::istream& is) {
    int d, m, y, h, min, s;
    char slash1, slash2, space, colon1, colon2;
    
    if (is >> d >> slash1 >> m >> slash2 >> y >> space >> h >> colon1 >> min >> colon2 >> s) {
        if (slash1 == '/' && slash2 == '/' && space == ' ' && colon1 == ':' && colon2 == ':') {
            value = 0;
            value |= static_cast<u_int64_t>(s);
            value |= static_cast<u_int64_t>(min) << 6;
            value |= static_cast<u_int64_t>(h) << 12;
            value |= static_cast<u_int64_t>(d) << 17;
            value |= static_cast<u_int64_t>(m) << 22;
            value |= static_cast<u_int64_t>(y) << 26;
        } else {
            is.setstate(std::ios::failbit);
        }
    } else {
        is.setstate(std::ios::failbit);
    }

    return is;
}

std::string Datetime::str() {
    u_int8_t year1 = (year() >> 8) & 0xFF;
    u_int8_t year2 = year() & 0xFF;

    u_int8_t data[] = {day(), '/', month(), '/', year1, year2, ' ', hour(), ':', minute(), ':', second()};
    size_t arraySize = sizeof(data) / sizeof(data[0]);

    std::string result(reinterpret_cast<const char*>(data), arraySize);
    return result;
}

u_int8_t Datetime::day() {
    return value & 0x1F;
}

u_int8_t Datetime::month() {
    return (value >> 5) & 0x0F;
}

u_int16_t Datetime::year() {
    return (value >> 9) & 0xFFF;
}

u_int8_t Datetime::hour() {
    return (value >> 21) & 0x1F;
}

u_int8_t Datetime::minute() {
    return (value >> 26) & 0x3F;
}

u_int8_t Datetime::second() {
    return (value >> 32) & 0x3F;
}

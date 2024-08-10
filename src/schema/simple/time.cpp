#include "time.hpp"

std::ostream& Time::print(std::ostream& os) {
    os << str();
    return os;
}

std::istream& Time::read(std::istream& is) {
    int h, min, s;
    char colon1, colon2;
    
    if (is >> h >> colon1 >> min >> colon2 >> s) {
        if (colon1 == ':' && colon2 == ':') {
            value = 0;
            value |= static_cast<u_int64_t>(h);
            value |= static_cast<u_int64_t>(min) << 6;
            value |= static_cast<u_int64_t>(s) << 12;
        } else {
            is.setstate(std::ios::failbit);
        }
    } else {
        is.setstate(std::ios::failbit);
    }

    return is;
}

std::string Time::str() {
    u_int8_t data[] = {hour(), ':', minute(), ':', second()};
    size_t arraySize = sizeof(data) / sizeof(data[0]);

    std::string result(reinterpret_cast<const char*>(data), arraySize);
    return result;
}

u_int8_t Time::hour() {
    return value & 0x1F;
}

u_int8_t Time::minute() {
    return (value >> 5) & 0x0F;
}

u_int8_t Time::second() {
    return (value >> 9) & 0xFFF;
}

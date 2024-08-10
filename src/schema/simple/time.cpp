#include "time.hpp"

std::string Time::print() {
    u_int8_t data[] = {hour(), ':', minute(), ':', second()};
    size_t arraySize = sizeof(data) / sizeof(data[0]);

    std::string result(reinterpret_cast<const char*>(data), arraySize);
    return result;
}

void Time::read(std::string data) {
    value = 0;
    int h, min, s;
    char colon1, colon2;
    
    std::stringstream is(data);
    if (is >> h >> colon1 >> min >> colon2 >> s) {
        if (colon1 == ':' && colon2 == ':') {
            value |= static_cast<u_int64_t>(h);
            value |= static_cast<u_int64_t>(min) << 6;
            value |= static_cast<u_int64_t>(s) << 12;
        } else {
            is.setstate(std::ios::failbit);
        }
    }
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

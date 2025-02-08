#include "simpleTypes.hpp"

std::string String::print() {
    std::string result;
    result = result + preffix;
    for(char ch : value.tokens)
        result = result + ch;
    result = result + suffix;
    return result;
}

void String::read(std::string data) {
    char ch;
    std::string punctuation = ",;:()\"—!?.";
    std::stringstream is(data);

    preffix = 0x0;
    suffix = 0x0;

    if (punctuation.find(is.peek()) != std::string::npos) {
        is >> ch;
        preffix = ch;
    }

    while (punctuation.find(is.peek()) == std::string::npos) {
        is >> ch;
        value.tokens.push_back(ch);
    }

    if (punctuation.find(is.peek()) != std::string::npos) {
        is >> ch;
        suffix = ch;
    }
}

std::string Duration::print() {
    return std::to_string(value);
}

void Duration::read(std::string data) {
    std::stringstream is(data);
    is >> value;
}

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

std::string Datetime::print() {
    u_int8_t year1 = (year() >> 8) & 0xFF;
    u_int8_t year2 = year() & 0xFF;

    u_int8_t data[] = {day(), '/', month(), '/', year1, year2, ' ', hour(), ':', minute(), ':', second()};
    size_t arraySize = sizeof(data) / sizeof(data[0]);

    std::string result(reinterpret_cast<const char*>(data), arraySize);
    return result;
}

void Datetime::read(std::string data) {
    value = 0;
    int d, m, y, h, min, s;
    char slash1, slash2, space, colon1, colon2;
    
    std::stringstream is(data);
    if (is >> d >> slash1 >> m >> slash2 >> y >> space >> h >> colon1 >> min >> colon2 >> s) {
        if (slash1 == '/' && slash2 == '/' && space == ' ' && colon1 == ':' && colon2 == ':') {
            value |= static_cast<u_int64_t>(s);
            value |= static_cast<u_int64_t>(min) << 6;
            value |= static_cast<u_int64_t>(h) << 12;
            value |= static_cast<u_int64_t>(d) << 17;
            value |= static_cast<u_int64_t>(m) << 22;
            value |= static_cast<u_int64_t>(y) << 26;
        }
    }
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

std::string Datetime::print() {
    u_int8_t year1 = (year() >> 8) & 0xFF;
    u_int8_t year2 = year() & 0xFF;

    u_int8_t data[] = {day(), '/', month(), '/', year1, year2, ' ', hour(), ':', minute(), ':', second()};
    size_t arraySize = sizeof(data) / sizeof(data[0]);

    std::string result(reinterpret_cast<const char*>(data), arraySize);
    return result;
}

void Datetime::read(std::string data) {
    value = 0;
    int d, m, y, h, min, s;
    char slash1, slash2, space, colon1, colon2;
    
    std::stringstream is(data);
    if (is >> d >> slash1 >> m >> slash2 >> y >> space >> h >> colon1 >> min >> colon2 >> s) {
        if (slash1 == '/' && slash2 == '/' && space == ' ' && colon1 == ':' && colon2 == ':') {
            value |= static_cast<u_int64_t>(s);
            value |= static_cast<u_int64_t>(min) << 6;
            value |= static_cast<u_int64_t>(h) << 12;
            value |= static_cast<u_int64_t>(d) << 17;
            value |= static_cast<u_int64_t>(m) << 22;
            value |= static_cast<u_int64_t>(y) << 26;
        }
    }
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

std::string Year::print() {
    return std::string(value);
}

void Year::read(std::string data) {
    std::stringstream is(data);
    is >> value;
}

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

std::string Month::print() {
    return std::string(value);
}

void Month::read(std::string data) {
    std::stringstream is(data);
    is >> value;
}

std::string Day::print() {
    return std::string(value);
}

void Day::read(std::string data) {
    std::stringstream is(data);
    is >> value;
}

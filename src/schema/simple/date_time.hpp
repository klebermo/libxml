#ifndef date_time_hpp
#define date_time_hpp

#include "../simple.hpp"

class Datetime : public simpleType {
private:
    u_int64_t value;
public:
    std::ostream& print(std::ostream& os);
    std::istream& read(std::istream& is);
    std::string str();

    u_int8_t day();
    u_int8_t month();
    u_int16_t year();
    u_int8_t hour();
    u_int8_t minute();
    u_int8_t second();
};

#endif

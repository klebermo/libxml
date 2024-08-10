#ifndef time_hpp
#define time_hpp

#include "../simple.hpp"

class Time : public simpleType {
private:
    u_int32_t value;
public:
    std::string print();
    void read(std::string data);

    u_int8_t hour();
    u_int8_t minute();
    u_int8_t second();
};

#endif

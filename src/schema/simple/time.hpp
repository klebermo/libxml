#ifndef time_hpp
#define time_hpp

#include "../simple.hpp"

class Time : public simpleType {
private:
    u_int32_t value;
public:
    std::ostream& print(std::ostream& os);
    std::istream& read(std::istream& is);
    std::string str();

    u_int8_t hour();
    u_int8_t minute();
    u_int8_t second();
};

#endif

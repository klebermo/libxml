#ifndef date_hpp
#define date_hpp

#include "../simple.hpp"

class Date : public simpleType {
private:
    u_int32_t value;
public:
    std::ostream& print(std::ostream& os);
    std::istream& read(std::istream& is);
    std::string str();

    u_int8_t day();
    u_int8_t month();
    u_int16_t year();
};

#endif

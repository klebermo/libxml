#ifndef simple_hpp
#define simple_hpp

#include "any.hpp"

enum Type {
    string,
    duration,
    dateTime,
    time_,
    date_,
    yearMonth,
    year,
    monthDay,
    day,
    month
};

Type get_type(std::string value);

class simpleType : public Any {
public:
    friend void operator<<(simpleType& type, std::string value) {
        type.read(value);
    }
};

#endif

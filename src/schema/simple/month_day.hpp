#ifndef month_day_hpp
#define month_day_hpp

#include "../simple.hpp"

class MonthDay : public simpleType {
private:
    char value[4];
public:
    std::string print();
    void read(std::string data);
};

#endif

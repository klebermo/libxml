#ifndef year_month_hpp
#define year_month_hpp

#include "../simple.hpp"

class YearMonth : public simpleType {
private:
    char value[6];
public:
    std::string print();
    void read(std::string data);
};

#endif

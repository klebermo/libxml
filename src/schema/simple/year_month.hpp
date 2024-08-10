#ifndef year_month_hpp
#define year_month_hpp

#include "../simple.hpp"

class YearMonth : public simpleType {
private:
    char value[6];
public:
    std::ostream& print(std::ostream& os);
    std::istream& read(std::istream& is);
    std::string str();
};

#endif

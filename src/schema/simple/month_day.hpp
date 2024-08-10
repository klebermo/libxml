#ifndef month_day_hpp
#define month_day_hpp

#include "../simple.hpp"

class MonthDay : public simpleType {
private:
    char value[4];
public:
    std::ostream& print(std::ostream& os);
    std::istream& read(std::istream& is);
    std::string str();
};

#endif

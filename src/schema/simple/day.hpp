#ifndef day_hpp
#define day_hpp

#include "../simple.hpp"

class Day : public simpleType {
private:
    char value[2];
public:
    std::ostream& print(std::ostream& os);
    std::istream& read(std::istream& is);
    std::string str();
};

#endif

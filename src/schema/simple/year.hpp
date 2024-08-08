#ifndef year_hpp
#define year_hpp

#include "../simple.hpp"

class Year : public simpleType {
private:
    char value[2];
public:
    std::ostream& print(std::ostream& os);
    std::istream& read(std::istream& is);
    std::string str();
};

#endif

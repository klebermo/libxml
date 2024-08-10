#ifndef day_hpp
#define day_hpp

#include "../simple.hpp"

class Day : public simpleType {
private:
    char value[2];
public:
    std::string print();
    void read(std::string data);
};

#endif

#ifndef year_hpp
#define year_hpp

#include "../simple.hpp"

class Year : public simpleType {
private:
    char value[2];
public:
    std::string print();
    void read(std::string data);
};

#endif

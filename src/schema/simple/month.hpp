#ifndef month_hpp
#define month_hpp

#include "../simple.hpp"

class Month : public simpleType {
private:
    char value[2];
public:
    std::string print();
    void read(std::string data);
};

#endif

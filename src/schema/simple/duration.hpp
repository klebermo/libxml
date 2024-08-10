#ifndef duration_hpp
#define duration_hpp

#include "../simple.hpp"

class Duration : public simpleType {
private:
    long value;
public:
    std::string print();
    void read(std::string data);
};

#endif

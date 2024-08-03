#ifndef simple_hpp
#define simple_hpp

#include "any.hpp"

class simpleType : public Any {
private:
    //
public:
    simpleType * get();
    void set(simpleType * value);
    simpleType * parse(std::string value);
};

#endif

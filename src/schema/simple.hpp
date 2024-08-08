#ifndef simple_hpp
#define simple_hpp

#include "any.hpp"

class simpleType : public Any {
public:
    friend std::ostream& operator<<(std::ostream& os, simpleType& type);
    friend std::istream& operator>>(std::istream& is, simpleType& type);
};

#endif

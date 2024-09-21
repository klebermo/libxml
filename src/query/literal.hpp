#ifndef literal_hpp
#define literal_hpp

#include "expression.hpp"

class Literal : public Expression {
private:
    std::string value;
public:
    Literal(const std::string& val) : value(val) {}
};

#endif

#ifndef variable_hpp
#define variable_hpp

#include "expression.hpp"

class Variable : public Expression {
private:
    std::string name;
    std::string value;
public:
    Variable(const std::string& name, const std::string& value) : name(name), value(value) {}
    std::string evaluate();
};

#endif

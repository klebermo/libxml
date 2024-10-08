#ifndef condition_hpp
#define condition_hpp

#include "expression.hpp"

class Condition : public Expression {
private:
    std::string operand1;
    char op;
    std::string operand2;
public:
    Condition();
    Condition(std::string value);
    std::string evaluate();
};

#endif

#ifndef function_hpp
#define function_hpp

#include "expression.hpp"

class Function : public Expression {
private:
    std::string name;
    std::vector<Expression> arguments;
public:
    Function(std::string value);
    std::string evaluate();
};

#endif

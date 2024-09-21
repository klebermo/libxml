#ifndef function_hpp
#define function_hpp

#include "expression.hpp"

class Function : public Expression {
private:
    std::string name;
    std::vector<Expression*> arguments;
public:
    Function(const std::string& name, const std::vector<Expression*>& args) : name(name), arguments(args) {}
    ~Function();
};

#endif

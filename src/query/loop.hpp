#ifndef loop_hpp
#define loop_hpp

#include "condition.hpp"

class Loop : public Expression {
private:
    Condition condition;
    std::vector<Expression> expressions;
public:
    Loop(std::string value);
    std::string evaluate();
};

#endif

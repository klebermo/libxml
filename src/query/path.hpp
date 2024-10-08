#ifndef path_hpp
#define path_hpp

#include "expression.hpp"

class PathExpr : public Expression {
private:
    std::vector<std::string> steps;
public:
    PathExpr(std::string value);
    std::string evaluate();
};

#endif

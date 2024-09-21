#ifndef path_hpp
#define path_hpp

#include "expression.hpp"

class Path : public Expression {
private:
    std::vector<std::string> steps;
public:
    Path();
};

#endif

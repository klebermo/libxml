#ifndef expression_hpp
#define expression_hpp

#include <string>
#include <vector>

class Expression {
public:
    virtual std::string  evaluate() = 0;
};

#endif

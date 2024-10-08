#ifndef query_hpp
#define query_hpp

#include "path.hpp"
#include "query/expression.hpp"

class Query {
private:
    std::vector<Expression> expressions;
public:
    Query(std::string value);
    void evaluate();
};

#endif

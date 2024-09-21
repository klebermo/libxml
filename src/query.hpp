#ifndef query_hpp
#define query_hpp

#include "path.hpp"

#include "query/literal.hpp"
#include "query/variable.hpp"
#include "query/function.hpp"
#include "query/path.hpp"
#include "query/flwor.hpp"

class Query {
private:
    Expression * root;
public:
    Query();
    Query(Expression * expr);
    ~Query();
    void addChild(Expression * expr);
    void execute();
};

#endif

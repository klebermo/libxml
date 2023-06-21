#ifndef xquery_hpp
#define xquery_hpp

#include "xpath.hpp"

class XQuery {
private:
    SyntaxTree * syntaxTree;
public:
    XQuery();
    ~XQuery();

    void parse(std::string query);
    std::string evaluate();
};

#endif

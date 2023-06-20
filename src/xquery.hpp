#ifndef xquery_hpp
#define xquery_hpp

#include "syntaxTree.hpp"

class XQuery {
private:
    SyntaxTree * syntaxTree;
public:
    XQuery();
    XQuery(std::string expression);
    ~XQuery();

    void parse(std::string query);
    Model * evaluate();
};

#endif

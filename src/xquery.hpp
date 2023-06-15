#ifndef xquery_hpp
#define xquery_hpp

#include "syntaxTree.hpp"

class XQuery {
private:
    SyntaxTree *syntaxTree;
public:
    XQuery();
    ~XQuery();

    void parse(std::string query);
    XML * execute(std::string value);
};

#endif

#ifndef xpath_hpp
#define xpath_hpp

#include "syntaxTree.hpp"

class XPath {
private:
    SyntaxTree * syntaxTree;
public:
    XPath();
    ~XPath();

    void parse(std::string expression);
    std::string evaluate();
};

#endif

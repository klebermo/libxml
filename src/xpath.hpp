#ifndef xpath_hpp
#define xpath_hpp

#include "xquery.hpp"

class XPath {
private:
    SyntaxTree * syntaxTree;
public:
    XPath();
    XPath(std::string expression);
    ~XPath();

    void parse(std::string expression);
    Model * evaluate();
};

#endif

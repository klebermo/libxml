#ifndef syntaxTree_hpp
#define syntaxTree_hpp

#include "model.hpp"
#include "syntaxNode.hpp"

class SyntaxTree {
private:
    SyntaxNode* root;
public:
    SyntaxTree();
    ~SyntaxTree();

    void setRoot(SyntaxNode* root);
    SyntaxNode* getRoot();

    void parse(std::string expression);
    Model * evaluate();
};

#endif

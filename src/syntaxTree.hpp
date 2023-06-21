#ifndef syntaxTree_hpp
#define syntaxTree_hpp

#include "syntaxNode.hpp"

class SyntaxTree {
private:
    SyntaxNode* root;
public:
    SyntaxTree();
    ~SyntaxTree();

    void setRoot(SyntaxNode* root);
    SyntaxNode* getRoot();

    void insert(SyntaxNode * node);

    void parse(std::string expression);
    std::string evaluate();
};

#endif

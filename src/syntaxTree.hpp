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

    void insert(NodeType type, int value);

    void parse(std::string expression);
    Model * evaluate();
};

#endif

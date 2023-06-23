#ifndef syntaxTree_hpp
#define syntaxTree_hpp

#include "syntaxNode.hpp"

enum Type {
    xpath,
    xquery
};

class SyntaxTree {
private:
    Type type;
    SyntaxNode* root;
public:
    SyntaxTree(Type type);
    ~SyntaxTree();

    void setType(Type type);
    Type getType();

    void setRoot(SyntaxNode* root);
    SyntaxNode* getRoot();

    void insert(SyntaxNode * node);
    std::vector<SyntaxNode*> traverse();
};

#endif

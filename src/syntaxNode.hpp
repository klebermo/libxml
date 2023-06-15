#ifndef syntaxNode_hpp
#define syntaxNode_hpp

#include <string>

class SyntaxNode {
private:
    SyntaxNode* left;
    SyntaxNode* right;
    SyntaxNode* parent;
    int type;
    int value;
public:
    SyntaxNode();
    ~SyntaxNode();

    void setLeft(SyntaxNode* left);
    void setRight(SyntaxNode* right);
    void setParent(SyntaxNode* parent);

    void setType(int type);
    void setValue(int value);

    SyntaxNode* getLeft();
    SyntaxNode* getRight();
    SyntaxNode* getParent();

    int getType();
    int getValue();
};

#endif

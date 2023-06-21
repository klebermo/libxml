#ifndef syntaxNode_hpp
#define syntaxNode_hpp

#include <string>

class SyntaxNode {
private:
    SyntaxNode * parent;
    SyntaxNode * left;
    SyntaxNode * right;
    char value;
public:
    SyntaxNode();
    ~SyntaxNode();

    void setParent(SyntaxNode * parent);
    void setLeft(SyntaxNode * left);
    void setRight(SyntaxNode * right);
    void setValue(char value);

    SyntaxNode * getParent();
    SyntaxNode * getLeft();
    SyntaxNode * getRight();
    char getValue();
};

#endif

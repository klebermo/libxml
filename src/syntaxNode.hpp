#ifndef syntaxNode_hpp
#define syntaxNode_hpp

#include "document.hpp"
#include "type.hpp"
#include "data.hpp"
#include "comment.hpp"

enum Type {
    slash,
    double_slash,
    dot,
    double_dot,
    attr,
    asterisk,
    text,
    lbracket,
    rbracket,
    lparen,
    rparen,
};

class SyntaxNode {
private:
    SyntaxNode * parent;
    SyntaxNode * left;
    SyntaxNode * right;
    Type type;
    std::string value;
public:
    SyntaxNode();
    SyntaxNode(Type type, std::string value);
    ~SyntaxNode();

    void setParent(SyntaxNode * parent);
    void setLeft(SyntaxNode * left);
    void setRight(SyntaxNode * right);
    void setType(Type type);
    void setValue(std::string value);

    SyntaxNode * getParent();
    SyntaxNode * getLeft();
    SyntaxNode * getRight();
    Type getType();
    std::string getValue();
};

#endif

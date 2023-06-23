#ifndef syntaxNode_hpp
#define syntaxNode_hpp

#include "document.hpp"
#include "type.hpp"
#include "data.hpp"
#include "comment.hpp"

const std::string xpathToken[] = {
    "/", "//", ".", "..", "@", "*", "[", "]", "(", ")"
};

const std::string xqueryToken[] = { 
    "for", "let", "where", "order by", "group by", "return",
    "element", "attribute", "text", "comment", "processing-instruction",
    "count", "sum", "avg", "min", "max",
    "union", "intersect", "except",
    "copy", "rename", "delete",
    "contains", "string-length", "substring", "string-concat", "distinct-values"
 };

class SyntaxNode {
private:
    SyntaxNode * parent;
    SyntaxNode * left;
    SyntaxNode * right;
    int type;
    std::string value;
public:
    SyntaxNode();
    SyntaxNode(int type, std::string value);
    ~SyntaxNode();

    void setParent(SyntaxNode * parent);
    void setLeft(SyntaxNode * left);
    void setRight(SyntaxNode * right);
    void setType(int type);
    void setValue(std::string value);

    SyntaxNode * getParent();
    SyntaxNode * getLeft();
    SyntaxNode * getRight();
    int getType();
    std::string getValue();
};

#endif

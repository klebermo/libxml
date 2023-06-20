#ifndef syntaxNode_hpp
#define syntaxNode_hpp

#include "model.hpp"
#include "instruction.hpp"

#include <string>

class SyntaxNode {
private:
    SyntaxNode* left;
    SyntaxNode* right;
    SyntaxNode* parent;
    Instruction* instruction;
public:
    SyntaxNode();
    ~SyntaxNode();

    void setLeft(SyntaxNode* left);
    void setRight(SyntaxNode* right);
    void setParent(SyntaxNode* parent);

    SyntaxNode* getLeft();
    SyntaxNode* getRight();
    SyntaxNode* getParent();

    void setInstruction(Instruction* instruction);
    Instruction* getInstruction();
};

#endif

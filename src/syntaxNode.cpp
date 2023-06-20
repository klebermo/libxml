#include "syntaxNode.hpp"

SyntaxNode::SyntaxNode() {
    this->left = nullptr;
    this->right = nullptr;
    this->parent = nullptr;
    this->instruction = nullptr;
}

SyntaxNode::~SyntaxNode() {
    delete this->left;
    delete this->right;
    delete this->parent;
    delete this->instruction;
}

void SyntaxNode::setLeft(SyntaxNode* left) {
    this->left = left;
}

void SyntaxNode::setRight(SyntaxNode* right) {
    this->right = right;
}

void SyntaxNode::setParent(SyntaxNode* parent) {
    this->parent = parent;
}

SyntaxNode* SyntaxNode::getLeft() {
    return this->left;
}

SyntaxNode* SyntaxNode::getRight() {
    return this->right;
}

SyntaxNode* SyntaxNode::getParent() {
    return this->parent;
}

void SyntaxNode::setInstruction(Instruction* instruction) {
    this->instruction = instruction;
}

Instruction* SyntaxNode::getInstruction() {
    return this->instruction;
}

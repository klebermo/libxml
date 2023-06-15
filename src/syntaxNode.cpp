#include "syntaxNode.hpp"

SyntaxNode::SyntaxNode() {
    this->type = 0;
    this->value = 0;
    this->left = nullptr;
    this->right = nullptr;
}

SyntaxNode::~SyntaxNode() {
    delete this->left;
    delete this->right;
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

void SyntaxNode::setType(int type) {
    this->type = type;
}

void SyntaxNode::setValue(int value) {
    this->value = value;
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

int SyntaxNode::getType() {
    return this->type;
}

int SyntaxNode::getValue() {
    return this->value;
}

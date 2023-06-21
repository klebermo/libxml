#include "syntaxNode.hpp"

SyntaxNode::SyntaxNode() {
    this->parent = nullptr;
    this->left = nullptr;
    this->right = nullptr;
    this->value = '\0';
}

SyntaxNode::~SyntaxNode() {
    delete this->parent;
    delete this->left;
    delete this->right;
}

void SyntaxNode::setParent(SyntaxNode * parent) {
    this->parent = parent;
}

void SyntaxNode::setLeft(SyntaxNode * left) {
    this->left = left;
}

void SyntaxNode::setRight(SyntaxNode * right) {
    this->right = right;
}

void SyntaxNode::setValue(char value) {
    this->value = value;
}

SyntaxNode * SyntaxNode::getParent() {
    return this->parent;
}

SyntaxNode * SyntaxNode::getLeft() {
    return this->left;
}

SyntaxNode * SyntaxNode::getRight() {
    return this->right;
}

char SyntaxNode::getValue() {
    return this->value;
}

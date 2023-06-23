#include "syntaxNode.hpp"

SyntaxNode::SyntaxNode() {
    this->parent = nullptr;
    this->left = nullptr;
    this->right = nullptr;
}

SyntaxNode::SyntaxNode(int type, std::string value) {
    this->parent = nullptr;
    this->left = nullptr;
    this->right = nullptr;
    this->type = type;
    this->value = value;
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

void SyntaxNode::setType(int type) {
    this->type = type;
}

void SyntaxNode::setValue(std::string value) {
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

int SyntaxNode::getType() {
    return this->type;
}

std::string SyntaxNode::getValue() {
    return this->value;
}

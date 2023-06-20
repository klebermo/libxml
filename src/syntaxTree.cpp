#include "syntaxTree.hpp"

SyntaxTree::SyntaxTree() {
    this->root = nullptr;
}

SyntaxTree::~SyntaxTree() {
    delete this->root;
}

void SyntaxTree::setRoot(SyntaxNode* root) {
    this->root = root;
}

SyntaxNode* SyntaxTree::getRoot() {
    return this->root;
}

void SyntaxTree::insert(NodeType type, int value) {
    //
}

void SyntaxTree::parse(std::string expression) {
    //
}

Model * SyntaxTree::evaluate() {
    return nullptr;
}

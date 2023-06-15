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

void SyntaxTree::parse(std::string expression) {
    //
}

XML * SyntaxTree::evaluate(std::string value) {
    return nullptr;
}

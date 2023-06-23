#include "syntaxTree.hpp"

SyntaxTree::SyntaxTree(Type type) {
    this->type = type;
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

void SyntaxTree::setType(Type type) {
    this->type = type;
}

Type SyntaxTree::getType() {
    return this->type;
}

void SyntaxTree::insert(SyntaxNode * node) {
    if(root == nullptr) {
        root = node;
        return;
    }

    SyntaxNode * current = root;
    while(true) {
        if(node->getValue() < current->getValue()) {
            if(current->getLeft() == nullptr) {
                current->setLeft(node);
                node->setParent(current);
                break;
            } else {
                current = current->getLeft();
            }
        } else {
            if(current->getRight() == nullptr) {
                current->setRight(node);
                node->setParent(current);
                break;
            } else {
                current = current->getRight();
            }
        }
    }
}

std::vector<SyntaxNode*> SyntaxTree::traverse() {
    std::vector<SyntaxNode*> result;
    return result;
}

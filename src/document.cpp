#include "document.hpp"

Document::Document(std::string input) {
    root = new Element(input);
}

Document::~Document() {
    delete root;
}

std::vector<Element *> Document::getElementsByTagName(std::string name) {
    return root->getElementsByTagName(name);
}

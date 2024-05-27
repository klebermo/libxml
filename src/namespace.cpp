#include "namespace.hpp"

Namespace::Namespace(std::string name, std::string data) {
    this->name = name;
    this->root = new Element(name, data);
}

Namespace::~Namespace() {
    delete root;
}

std::string Namespace::getName() {
    return name;
}

std::vector<Element *> Namespace::getElementsByTagName(std::string name) {
    return root->getElementsByTagName(name);
}

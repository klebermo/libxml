#include "namespace.hpp"

Namespace::Namespace(std::string value) {
    this->name = "";
    this->root = new Element(value);
}

Namespace::~Namespace() {
    //
}

std::string Namespace::getName() {
    return this->name;
}

std::vector<Element *> Namespace::getElementsByTagName(std::string tagname) {
    return std::vector<Element *>();
}

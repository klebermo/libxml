#include "xml.hpp"

Xml::Xml(std::string data) {
    this->root = new Element(data);
}

Xml::~Xml() {
    delete root;
}

std::vector<Element *> Xml::getElementsByTagName(std::string name) {
    return root->getElementsByTagName(name);
}

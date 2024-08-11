#include "namespace.hpp"

Namespace::Namespace(std::string value) {
    this->name = "";
    this->root = new Tag(value);
}

Namespace::~Namespace() {
    //
}

std::string Namespace::getName() {
    return this->name;
}

std::vector<Element *> Namespace::getElementsByTagName(std::string tagname) {
    std::vector<Element *> result;

    if(root->getName().compare(tagname) == 0) {
        result.push_back(root);
    } else {
        result = root->getElementsByTagName(tagname);
    }

    return result;
}

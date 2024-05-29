#include "document.hpp"

Document::Document(std::string prefix, std::string data) {
    namespaces.push_back(new Namespace("", data));
}

Document::~Document() {
    for(size_t i=1; i<namespaces.size(); i++) {
        delete namespaces[i];
    }
}

std::vector<Element *> Document::getElementsByTagName(std::string name) {
    return namespaces[0]->getElementsByTagName(name);
}

std::vector<Element *> Document::getElementsByTagName(std::string prefix, std::string name) {
    for(size_t i=1; i<namespaces.size(); i++) {
        if(namespaces[i]->getName() == prefix) {
            return namespaces[i]->getElementsByTagName(name);
        }
    }
    return std::vector<Element *>();
}

#include "xml.hpp"

Xml::Xml(std::string data) {
    root = new Element(data);
}

std::list<Element> Xml::getElementsByTagName(std::string name) {
    return root->getElementsByTagName(name);
}

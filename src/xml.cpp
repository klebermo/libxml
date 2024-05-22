#include "xml.hpp"

Xml::Xml(std::string data) {
    root = new Element(data);
}

Element Xml::getElementByTagName(std::string name) {
    std::vector<Element> values = this->getElementsByTagName(name);
    if(values.empty()) {
        return Element();
    } else {
        return values[0];
    }
}

std::vector<Element> Xml::getElementsByTagName(std::string name) {
    return root->getElementsByTagName(name);
}

Element Xml::innerHTML() {
    return root->innerHTML();
}

std::string Xml::innerText() {
    return root->innerText();
}

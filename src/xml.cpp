#include "xml.hpp"

Xml::Xml(std::string input) {
    this->document = new Document(input);
}

Xml::~Xml() {
    delete document;
}

Document * Xml::getDocument() {
    return this->document;
}

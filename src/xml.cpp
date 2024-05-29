#include "xml.hpp"

Xml::Xml(std::string data) {
    this->prolog = new Prolog(data);
    this->document = new Document("", data);
}

Xml::~Xml() {
    delete document;
}

Document * Xml::getDocument() {
    return this->document;
}

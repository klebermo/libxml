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

std::string Xml::evaluatePath(std::string value) {
    return "";
}

std::string Xml::evaluateQuery(std::string value) {
    return "";
}

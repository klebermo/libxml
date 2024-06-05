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

void Xml::parse(std::string input) {
    std::regex doctype_regex("(<!DOCTYPE\\s+([a-zA-Z_][a-zA-Z0-9_\\-]*)\\s*(SYSTEM\\s+\"([^\"]+)\"|PUBLIC\\s+\"([^\"]+)\"\\s+\"([^\"]+)\"|\\[.*\\])?\\s*>)");
    std::regex prolog_regex("(<\\?xml\\s+version=\"([^\"]+)\"\\s+encoding=\"([^\"]+)\"(?:\\s+standalone=\"([^\"]+)\")?\\s*\\?>)");

    std::smatch doctype_matches;
    std::smatch prolog_matches;

    while (std::regex_search(input, doctype_matches, doctype_regex)) {
        std::string rootElement = doctype_matches[1];
        std::string systemType = doctype_matches[2].matched ? doctype_matches[2].str() : "";
        std::string systemId = doctype_matches[3].matched ? doctype_matches[3].str() : "";
        std::string publicId = doctype_matches[4].matched ? doctype_matches[4].str() : "";
        std::string internalSubset = doctype_matches[5].matched ? doctype_matches[5].str() : "";

        input = doctype_matches.suffix().str();
    }

    while (std::regex_search(input, prolog_matches, prolog_regex)) {
        this->version = prolog_matches[2].matched ? prolog_matches[2].str() : "";
        this->encoding = prolog_matches[3].matched ? prolog_matches[3].str() : "";
        this->standalone = prolog_matches[4].matched ? prolog_matches[4].str() : "";

        input = prolog_matches.suffix().str();
    }
}

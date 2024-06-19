#include "xml.hpp"

Xml::Xml(std::string input) {
    this->parse_prolog(input);
    this->parse_doctype(input);
    this->document = new Document(input);
}

Xml::~Xml() {
    delete document;
}

Document * Xml::getDocument() {
    return this->document;
}

void Xml::parse_prolog(std::string input) {
    std::regex prolog_regex("(<\\?xml\\s+version=\"([^\"]+)\"\\s+encoding=\"([^\"]+)\"(?:\\s+standalone=\"([^\"]+)\")?\\s*\\?>)");
    std::smatch prolog_matches;

    while (std::regex_search(input, prolog_matches, prolog_regex)) {
        this->version = prolog_matches[2].matched ? prolog_matches[2].str() : "";
        this->encoding = prolog_matches[3].matched ? prolog_matches[3].str() : "";
        this->standalone = prolog_matches[4].matched ? prolog_matches[4].str() : "";

        std::cout << "version: " << version << std::endl;
        std::cout << "encoding: " << encoding << std::endl;
        std::cout << "standalone: " << standalone << std::endl;

        input = prolog_matches.suffix().str();
    }
}

void Xml::parse_doctype(std::string input) {
    std::regex doctype_regex("(<!DOCTYPE\\s+([a-zA-Z_][a-zA-Z0-9_\\-]*)\\s*(SYSTEM\\s+\"([^\"]+)\"|PUBLIC\\s+\"([^\"]+)\"\\s+\"([^\"]+)\"|\\[.*\\])?\\s*>)");
    std::smatch doctype_matches;

    while (std::regex_search(input, doctype_matches, doctype_regex)) {
        std::string rootElement = doctype_matches[1];
        std::string systemType = doctype_matches[2].matched ? doctype_matches[2].str() : "";
        std::string systemId = doctype_matches[3].matched ? doctype_matches[3].str() : "";
        std::string publicId = doctype_matches[4].matched ? doctype_matches[4].str() : "";
        std::string internalSubset = doctype_matches[5].matched ? doctype_matches[5].str() : "";

        std::cout << "rootElement: " << rootElement << std::endl;
        std::cout << "systemType: " << systemType << std::endl;
        std::cout << "systemId: " << systemId << std::endl;
        std::cout << "publicId: " << publicId << std::endl;
        std::cout << "internalSubset: " << internalSubset << std::endl;

        input = doctype_matches.suffix().str();
    }
}

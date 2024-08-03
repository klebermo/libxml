#include "document.hpp"

Prolog::Prolog(std::string data) {
    std::regex expressionHandler(R"(<\?xml\s+version="([0-9.]+)\"\s+encoding=\"([^\s\"]+)\"\s+standalone=\"(yes|no)\"\?>)");
    std::smatch match;
    if (std::regex_search(data, match, expressionHandler)) {
        this->version = match[1].str();
        this->encoding = match[2].str();
        this->standalone = (match[3].str() == "yes");
    }
}

std::string Prolog::getVersion() {
    return this->version;
}

std::string Prolog::getEncoding() {
    return this->encoding;
}

bool Prolog::isStandalone() {
    return this->standalone;
}

DTD::DTD(std::string data) {
    std::regex expressionHandler(R"(<\!DOCTYPE\s+(\w+)\s+(PUBLIC\s+\"[^\"]+\"\s+\"[^\"]+\"|SYSTEM\s+\"[^\"]+\")?\s*(\[.*\])?\s*>)");
    std::smatch match;
    if (std::regex_search(data, match, expressionHandler)) {
        this->name = match[1].str();
        this->externalId = match[2].str();
        this->systemId = match[3].str();
        this->internalSubset = match[4].str();
    }
}

std::string DTD::getName() {
    return this->name;
}

std::string DTD::getExternalId() {
    return this->externalId;
}

std::string DTD::getSystemId() {
    return this->systemId;
}

std::string DTD::getInternalSubset() {
    return this->internalSubset;
}

Document::Document(std::string input) {
    prolog = new Prolog(input);
    dtd = new DTD(input);
}

Document::~Document() {
    delete prolog;
    delete dtd;
}

std::vector<Element *> Document::getElementsByTagName(std::string prefix, std::string tagname) {
    if(prefix.empty()) {
        return namespaces[""]->getElementsByTagName(tagname);
    } else {
        return namespaces[prefix]->getElementsByTagName(tagname);
    }
}

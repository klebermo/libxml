#include "xpath.hpp"

XPath::XPath() {
    syntaxTree = new SyntaxTree();
}

XPath::~XPath() {
    delete syntaxTree;
}

void XPath::parse(std::string expression) {
    //
}

std::string XPath::evaluate() {
    return "";
}

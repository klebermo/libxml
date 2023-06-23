#include "xpath.hpp"

XPath::XPath() {
    syntaxTree = new SyntaxTree(xpath);
}

XPath::~XPath() {
    delete syntaxTree;
}

void XPath::parse(std::string expression) {
    for(std::string::size_type i = 0; i<expression.size(); i++) {
        char c = expression[i];
        //
    }
}

std::string XPath::evaluate() {
    std::string result;
    
    std::vector<SyntaxNode *> nodes = syntaxTree->traverse();
    for(SyntaxNode * node : nodes) {
        //
    }

    return result;
}

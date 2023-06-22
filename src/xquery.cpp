#include "xquery.hpp"

XQuery::XQuery() {
    syntaxTree = new SyntaxTree();
}

XQuery::~XQuery() {
    delete syntaxTree;
}

void XQuery::parse(std::string query) {
    //
}

std::string XQuery::evaluate() {
    return "";
}

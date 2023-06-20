#include "xquery.hpp"

XQuery::XQuery() {
    //
}

XQuery::XQuery(std::string expression) {
    this->parse(expression);
}

XQuery::~XQuery() {
    //
}

void XQuery::parse(std::string query) {
    //
}

Model * XQuery::evaluate() {
    return nullptr;
}

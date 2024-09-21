#include "query.hpp"

Query::Query() {
    //
}

Query::Query(Expression * expr) {
    //
}

Query::~Query() {
    delete root;
}

void Query::addChild(Expression * expr) {
    //
}

void Query::execute() {
    //
}

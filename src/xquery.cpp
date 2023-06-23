#include "xquery.hpp"

XQuery::XQuery() {
    syntaxTree = new SyntaxTree(xquery);
}

XQuery::~XQuery() {
    delete syntaxTree;
}

void XQuery::parse(std::string query) {
    int start = 0;
    int end = query.find_first_not_of(" ", start);
    std::string token = query.substr(start, end - start);

    while(end < query.size()) {
        //
        start = end + 1;
        end = query.find_first_not_of(" ", start);
    }
}

std::string XQuery::evaluate() {
    std::string result;
    
    std::vector<SyntaxNode *> nodes = syntaxTree->traverse();
    for(SyntaxNode * node : nodes) {
        std::string query = node->getValue();
        int start = 0;
        int end = query.find_first_not_of(" ", start);
        std::string token = query.substr(start, end - start);

        while(end < query.size()) {
            //
            start = end + 1;
            end = query.find_first_not_of(" ", start);
        }
    }

    return result;
}

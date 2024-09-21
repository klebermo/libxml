#include "path.hpp"

Node::Node() {}

Node::Node(NodeType t, const std::string& v) : type(t), value(v) {}

void Node::addChild(const std::shared_ptr<Node>& child) {
    children.push_back(child);
}

Path::Path() {}

Path::~Path() {
    delete root;
}

void Path::addChild(Node * node) {
    if( root == nullptr ) {
        //
    } else {
        //
    }
}

void Path::evaluate() {
    //
}

#ifndef path_hpp
#define path_hpp

#include "element.hpp"

enum class NodeType {
    ELEMENT,
    ATTRIBUTE,
    OPERATOR
};

class Node {
private:
    NodeType type;
    std::string value;
    std::vector<std::shared_ptr<Node>> children;
public:
    Node();
    Node(NodeType t, const std::string& v);
    void addChild(const std::shared_ptr<Node>& child);
};

class Path {
private:
    Node * root;
public:
    Path();
    ~Path();
    void addChild(Node * node);
    void evaluate();
};

#endif

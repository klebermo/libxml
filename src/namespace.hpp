#ifndef namespace_hpp
#define namespace_hpp

#include "query.hpp"

class Namespace {
private:
    std::string name;
    Element * root;
public:
    Namespace(std::string value);
    ~Namespace();
    std::string getName();
    std::vector<Element *> getElementsByTagName(std::string tagname);
};

#endif

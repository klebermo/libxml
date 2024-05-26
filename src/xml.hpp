#ifndef xml_hpp
#define xml_hpp

#include "query.hpp"

class Xml {
private:
    Element * root;
public:
    Xml(std::string data);
    ~Xml();
    std::vector<Element *> getElementsByTagName(std::string name);
};

#endif

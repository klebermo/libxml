#ifndef xml_hpp
#define xml_hpp

#include "query.hpp"

class Xml {
private:
    Element * root;
public:
    Xml(std::string data);

    Element getElementByTagName(std::string name);
    std::vector<Element> getElementsByTagName(std::string name);

    Element innerHTML();
    std::string innerText();
};

#endif

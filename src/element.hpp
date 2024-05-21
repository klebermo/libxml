#ifndef element_hpp
#define element_hpp

#include "model.hpp"

class Element {
private:
    std::string name;
    std::map<std::string, std::string> attributes;
    std::vector<Element> children;

    std::string getName();
    void setName(std::string value);

    std::map<std::string, std::string> get_attributes();
    void add_attribute(std::string key, std::string value);

    void add_child(Element child);
public:
    Element();
    Element(std::string data);
    std::list<Element> getElementsByTagName(std::string name);
};

#endif

#ifndef element_hpp
#define element_hpp

#include <string>
#include <map>
#include <list>

class Element {
private:
    std::string name;
    std::map<std::string, std::string> attributes;
    std::string text;
    std::list<Element> children;
public:
    Element(std::string data);
    std::list<Element> getElementsByTagName(std::string name);
};

#endif

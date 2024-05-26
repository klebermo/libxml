#ifndef element_hpp
#define element_hpp

#include "model.hpp"

class Element {
private:
    std::string name;
    std::map<std::string, std::string> attributes;
    std::string text;
    std::vector<Element *> children;
public:
    Element(std::string input);
    ~Element();

    std::string getName();
    void setName(std::string value);

    std::string getAttributeValue(std::string key);
    void setAttribute(std::string key, std::string value);

    std::vector<Element *> getElementsByTagName(std::string name);
    std::string getTextContent();
    void parse(std::string input);
};

class Text: public Element {
private:
    std::string content;
public:
    Text(std::string value);
    std::string textContent();
};

#endif

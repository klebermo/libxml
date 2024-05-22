#include <string>
#include <list>
#include <map>
#include <vector>
#include <regex>

#ifndef element_hpp
#define element_hpp

class Element {
private:
    std::string name;
    std::map<std::string, std::string> attributes;
    std::vector<Element*> children;

    void parse(Element * node, std::string input);
public:
    Element();
    Element(std::string input);
    Element(Element * node, std::string input);
    void add_child(Element * node);

    std::string getName();
    void setName(std::string value);

    std::string getAttributeValue(std::string key);
    void setAttribute(std::string key, std::string value);

    Element getElementByTagName(std::string name);
    std::vector<Element> getElementsByTagName(std::string name);

    Element innerHTML();
    std::string innerText();
};

class Text: public Element {
private:
    std::string content;
public:
    Text();
    Text(std::string value);
    std::string getContent();
    void setContent(std::string value);
};

#endif

#ifndef xml_hpp
#define xml_hpp

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
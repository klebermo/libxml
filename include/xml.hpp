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
    std::vector<Element *> children;
public:
    Element(std::string input);
    ~Element();

    std::string getName();
    void setName(std::string value);

    std::string getAttributeValue(std::string key);
    void setAttribute(std::string key, std::string value);

    std::vector<Element *> getElementsByTagName(std::string name);
    void parse(Element * node, std::string input);
};

class Text: public Element {
private:
    std::string content;
public:
    Text(std::string value);
    std::string textContent();
};

#endif

#ifndef namespace_hpp
#define namespace_hpp

class Namespace {
private:
    std::string name;
    Element * root;
public:
    Namespace(std::string name, std::string data);
    ~Namespace();
    std::string getName();
    std::vector<Element *> getElementsByTagName(std::string name);
};

#endif

#ifndef xml_hpp
#define xml_hpp

class Xml {
private:
    std::vector<Namespace *> namespaces;
public:
    Xml(std::string data);
    ~Xml();
    std::vector<Element *> getElementsByTagName(std::string name);
    std::vector<Element *> getElementsByTagName(std::string prefix, std::string name);
};

#endif

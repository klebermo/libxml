#ifndef element_hpp
#define element_hpp

#include "schema/simple.hpp"
#include "schema/complex.hpp"

class Attribute {
private:
    std::string key;
    std::string value;

    void parse(std::string data);
public:
    Attribute(std::string data);
    Attribute(std::string key, std::string value);

    std::string getKey();
    std::string getValue();
};

class Element {
private:
    std::string name;
    std::vector<Attribute> attributes;
    std::vector<Element *> children;

    void parse(std::string input);
public:
    Element(std::string input);
    ~Element();

    std::string getName();
    void setName(std::string value);

    std::vector<Element *> getElementsByTagName(std::string name);
    std::string getAttribute(std::string key);
};

class Text: public Element {
private:
    std::string content;
public:
    Text(std::string value);
    std::string textContent();
};

#endif

#ifndef element_hpp
#define element_hpp

#include "complexTypes.hpp"

class Attribute {
private:
    std::string key;
    simpleType * value;

    void parse(std::string data);
public:
    Attribute(std::string data);
    Attribute(std::string key, simpleType * value);

    std::string getKey();
    simpleType * getValue();
};

class Element {
protected:
    std::string name;
    std::vector<Attribute> attributes;
    std::vector<Element *> children;

    void parse(std::string input);
public:
    Element();
    Element(std::string input);
    virtual ~Element() = 0;

    std::string getName();
    void setName(std::string value);

    std::vector<Element *> getElementsByTagName(std::string name);
    simpleType * getAttribute(std::string key);

    virtual std::string textContent() = 0;
    Element * innerHTML();
};

class Tag : public Element {
public:
    Tag(std::string value);
    ~Tag();
    std::string textContent();
};

class Text: public Element {
private:
    std::vector<simpleType *> content;
public:
    Text(std::string value);
    ~Text();
    std::string textContent();
};

class Data: public Element {
private:
    std::string content;
public:
    Data(std::string value);
    ~Data();
    std::string textContent();
};

#endif

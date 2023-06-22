#ifndef element_hpp
#define element_hpp

#include "attribute.hpp"

class Element : public Tag {
protected:
    std::string key;
    std::string value;
    std::vector<Attribute> attributes;
    std::vector<Element> children;
public:
    Element();
    ~Element();

    std::string getKey();
    void setKey(std::string key);

    std::string getValue();
    void setValue(std::string value);

    std::vector<Attribute> getAttributes();
    void setAttributes(std::vector<Attribute> attributes);

    std::vector<Element> getChildren();
    void setChildren(std::vector<Element> children);

    Element * get(std::string key);
    std::string get_value(std::string key);

    void addChild(Tag * child);
    void addAttribute(Tag * attribute);

    void parse(std::string xml_string);
    std::string toString();
};

#endif

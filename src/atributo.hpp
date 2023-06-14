#ifndef atributo_hpp
#define atributo_hpp

#include "tag.hpp"

class Atributo : public Tag {
private:
    std::string key;
    std::string value;
public:
    Atributo();
    Atributo(std::string key, std::string value);
    ~Atributo();

    std::string getKey();
    void setKey(std::string key);
    
    std::string getValue();
    void setValue(std::string value);

    void addChild(Tag * child);
    void addAtributo(Tag * atributo);

    void parse(std::string xml_string);
    std::string toString();
};

#endif

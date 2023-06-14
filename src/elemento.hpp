#ifndef element_hpp
#define element_hpp

#include "atributo.hpp"

class Elemento : public Tag {
protected:
    std::string key;
    std::string value;
    std::vector<Atributo> atributos;
    std::vector<Elemento> children;
public:
    Elemento();
    ~Elemento();

    std::string getKey();
    void setKey(std::string key);

    std::string getValue();
    void setValue(std::string value);

    std::vector<Atributo> getAtributos();
    void setAtributos(std::vector<Atributo> atributos);

    std::vector<Elemento> getChildren();
    void setChildren(std::vector<Elemento> children);

    Elemento * get(std::string key);
    std::string get_value(std::string key);

    void addChild(Tag * child);
    void addAtributo(Tag * atributo);

    void parse(std::string xml_string);
    std::string toString();
};

#endif

#ifndef attribute_hpp
#define attribute_hpp

#include "tag.hpp"

class Attribute : public Tag {
private:
    std::string key;
    std::string value;
public:
    Attribute();
    Attribute(std::string key, std::string value);
    ~Attribute();

    std::string getKey();
    void setKey(std::string key);
    
    std::string getValue();
    void setValue(std::string value);

    void addChild(Tag * child) override;
    void addAttribute(Tag * attribute) override;

    void parse(std::string xml_string) override;
    std::string toString() override;
};

#endif

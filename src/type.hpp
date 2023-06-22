#ifndef type_hpp
#define type_hpp

#include "element.hpp"

class DocType : public Element {
private:
    std::string name;
    std::string id;
public:
    DocType();
    ~DocType() override;

    std::string getName();
    void setName(std::string name);

    std::string getId();
    void setId(std::string id);

    void parse(std::string xml_string) override;
    std::string toString() override;
};

#endif

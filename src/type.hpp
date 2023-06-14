#ifndef type_hpp
#define type_hpp

#include "elemento.hpp"

class DocType : public Elemento {
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

#ifndef namespace_hpp
#define namespace_hpp

#include "tag.hpp"

class Namespace : public Tag {
private:
    std::string name;
    std::string value;
public:
    Namespace();
    ~Namespace() override;

    std::string getName();
    void setName(std::string name);

    std::string getValue();
    void setValue(std::string value);

    void parse(std::string xml_string) override;
    std::string toString() override;
};

#endif

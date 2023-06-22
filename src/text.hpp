#ifndef text_hpp
#define text_hpp

#include "tag.hpp"

class Text : public Tag {
private:
    std::string name;
    std::string value;
public:
    Text();
    ~Text() override;

    std::string getName();
    void setName(std::string name);

    std::string getValue();
    void setValue(std::string value);

    void parse(std::string xml_string) override;
    std::string toString() override;
};

#endif

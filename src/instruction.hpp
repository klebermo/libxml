#ifndef instruction_hpp
#define instruction_hpp

#include "tag.hpp"

class Instruction : public Tag {
private:
    std::string name;
    std::string value;
public:
    Instruction();
    ~Instruction() override;

    std::string getName();
    void setName(std::string name);

    std::string getValue();
    void setValue(std::string value);

    void parse(std::string xml_string) override;
    std::string toString() override;
};

#endif

#ifndef comment_hpp
#define comment_hpp

#include "element.hpp"

class Comment : public Element {
private:
    std::string value;
public:
    Comment();
    ~Comment() override;

    std::string getValue();
    void setValue(std::string value);

    void parse(std::string xml_string) override;
    std::string toString() override;
};

#endif

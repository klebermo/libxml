#ifndef tag_hpp
#define tag_hpp

#include <string>
#include <vector>

class Tag {
public:
    Tag();
    virtual ~Tag() = 0;

    virtual void addChild(Tag * child) = 0;
    virtual void addAttribute(Tag * atributo) = 0;

    virtual void parse(std::string xml_string) = 0;
    virtual std::string toString() = 0;
};

#endif

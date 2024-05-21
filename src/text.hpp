#ifndef text_hpp
#define text_hpp

#include "element.hpp"

class Text: public Element {
private:
    std::string content;
public:
    Text();
    Text(std::string value);
    std::string getContent();
    void setContent(std::string value);
};

#endif

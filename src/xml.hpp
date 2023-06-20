#ifndef xml_hpp
#define xml_hpp

#include "decl.hpp"
#include "type.hpp"
#include "data.hpp"
#include "comment.hpp"
#include "xpath.hpp"
#include "xquery.hpp"

class XML {
private:
    Declaration * root;
public:
    XML();
    ~XML();

    Tag * getRoot();

    void parse(std::string xml_string);
    std::string toString();

    void parseFile(std::string file_path);

    XPath * getXPath(std::string expression);
    XQuery * getXQuery(std::string expression);
};

std::string_view ltrim(std::string_view str);
std::string_view rtrim(std::string_view str);
std::string_view trim(std::string_view str);

#endif

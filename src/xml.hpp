#ifndef xml_hpp
#define xml_hpp

#include "xquery.hpp"

class XML {
private:
    Document * root;
public:
    XML();
    ~XML();

    Tag * getRoot();

    void parse(std::string xml_string);
    std::string toString();

    void parseFile(std::string file_path);

    void evaluateXPath(std::string expression);
    void evaluateXQuery(std::string expression);
};

std::string_view ltrim(std::string_view str);
std::string_view rtrim(std::string_view str);
std::string_view trim(std::string_view str);

#endif

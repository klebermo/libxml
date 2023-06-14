#ifndef xml_hpp
#define xml_hpp

#include "declaration.hpp"
#include "type.hpp"
#include "data.hpp"
#include "comentario.hpp"

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
};

std::string_view ltrim(std::string_view str);
std::string_view rtrim(std::string_view str);
std::string_view trim(std::string_view str);

#endif

#ifndef xml_hpp
#define xml_hpp

#include "decl.hpp"
#include "type.hpp"
#include "data.hpp"
#include "comment.hpp"
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

    void evaluateXPath(std::string expression);
    void evaluateXQuery(std::string expression);
};

#endif

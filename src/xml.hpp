#ifndef xml_hpp
#define xml_hpp

#include "document.hpp"

class Xml {
private:
    std::string version;
    std::string encoding;
    std::string standalone;

    Document * document;

    void parse_prolog(std::string input);
    void parse_doctype(std::string input);
public:
    Xml(std::string input);
    ~Xml();
    Document * getDocument();
};

#endif

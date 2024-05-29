#ifndef xml_hpp
#define xml_hpp

#include "prolog.hpp"
#include "document.hpp"

class Xml {
private:
    Prolog * prolog;
    Document * document;
public:
    Xml(std::string data);
    ~Xml();
    Document * getDocument();
};

#endif

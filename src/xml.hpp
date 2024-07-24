#ifndef xml_hpp
#define xml_hpp

#include "document.hpp"

class Xml {
private:
    Document * document;
public:
    Xml(std::string input);
    ~Xml();
    Document * getDocument();
};

#endif

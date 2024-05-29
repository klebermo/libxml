#ifndef prolog_hpp
#define prolog_hpp

#include "document.hpp"

class Prolog {
private:
    void parse(std::string data);
public:
    Prolog(std::string data);
};

#endif

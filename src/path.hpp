#ifndef path_hpp
#define path_hpp

#include "element.hpp"

class Path {
private:
    std::vector<Element> nodes;
public:
    Path(std::string value);
    void evaluate();
};

#endif

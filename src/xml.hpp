#ifndef xml_hpp
#define xml_hpp

#include "namespace.hpp"

class Xml {
private:
    std::vector<Namespace *> namespaces;
public:
    Xml(std::string data);
    ~Xml();
    std::vector<Element *> getElementsByTagName(std::string name);
    std::vector<Element *> getElementsByTagName(std::string prefix, std::string name);
};

#endif

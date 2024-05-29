#ifndef document_hpp
#define document_hpp

#include "namespace.hpp"

class Document {
private:
    std::vector<Namespace *> namespaces;
public:
    Document(std::string prefix, std::string data);
    ~Document();
    std::vector<Element *> getElementsByTagName(std::string name);
    std::vector<Element *> getElementsByTagName(std::string prefix, std::string name);
};

#endif

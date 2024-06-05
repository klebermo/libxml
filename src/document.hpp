#ifndef document_hpp
#define document_hpp

#include "query.hpp"

class Document {
private:
    Element * root;
public:
    Document(std::string input);
    ~Document();
    std::vector<Element *> getElementsByTagName(std::string name);
};

#endif

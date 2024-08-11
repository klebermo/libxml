#ifndef document_hpp
#define document_hpp

#include "namespace.hpp"

class Prolog {
private:
    std::string version;
    std::string encoding;
    bool standalone;
public:
    Prolog(std::string data);
    std::string getVersion();
    std::string getEncoding();
    bool isStandalone();
};

class DTD {
private:
    std::string name;
    std::string externalId;
    std::string systemId;
    std::string internalSubset;
public:
    DTD(std::string data);
    std::string getName();
    std::string getExternalId();
    std::string getSystemId();
    std::string getInternalSubset();
};

class Document {
private:
    Prolog * prolog;
    DTD * dtd;
    std::vector<Namespace *> namespaces;
public:
    Document(std::string input);
    ~Document();
    std::vector<Element *> getElementsByTagName(std::string tagname);
    std::vector<Element *> getElementsByTagName(std::string prefix, std::string tagname);
};

#endif

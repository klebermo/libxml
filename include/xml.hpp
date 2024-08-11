#include <string>
#include <list>
#include <map>
#include <vector>
#include <regex>

#ifndef element_hpp
#define element_hpp

class Any {
public:
    virtual std::string print() = 0;
    virtual void read(std::string value) = 0;
};

class simpleType : public Any {
public:
    friend void operator<<(simpleType& type, std::string value) {
        type.read(value);
    }
};

class Attribute {
private:
    std::string key;
    simpleType * value;

    void parse(std::string data);
public:
    Attribute(std::string data);
    Attribute(std::string key, simpleType * value);

    std::string getKey();
    simpleType * getValue();
};

class Element {
private:
    std::string name;
    std::vector<Attribute> attributes;
    std::vector<Element *> children;

    void parse(std::string input);
public:
    Element();
    Element(std::string input);
    ~Element();

    std::string getName();
    void setName(std::string value);

    std::vector<Element *> getElementsByTagName(std::string name);
    simpleType * getAttribute(std::string key);
};

class Text: public Element {
private:
    std::vector<simpleType *> content;
public:
    Text(std::string value);
    std::string textContent();
};

class Data: public Element {
private:
    std::string content;
public:
    Data(std::string value);
    std::string getContent();
};

#endif

#ifndef namespace_hpp
#define namespace_hpp

class Namespace {
private:
    std::string name;
    Element * root;
public:
    Namespace(std::string value);
    ~Namespace();
    std::vector<Element *> getElementsByTagName(std::string tagname);
};

#endif

#ifndef document_hpp
#define document_hpp

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
    std::map<std::string, Namespace *> namespaces;
public:
    Document(std::string input);
    ~Document();
    std::vector<Element *> getElementsByTagName(std::string prefix, std::string tagname = "");
};

#endif

#ifndef xml_hpp
#define xml_hpp

class Xml {
private:
    Document * document;
public:
    Xml(std::string input);
    ~Xml();
    Document * getDocument();
};

#endif

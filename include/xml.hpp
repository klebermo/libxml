#include <string>
#include <list>
#include <map>
#include <vector>
#include <regex>

#ifndef element_hpp
#define element_hpp

class Attribute {
private:
    void parse(std::string data);
public:
    std::string key;
    std::string value;

    Attribute(std::string data);
    Attribute(std::string key, std::string value);
};

class Element {
private:
    std::string name;
    std::vector<Attribute> attributes;
    std::vector<Element *> children;

    void parse(std::string prefix, std::string input);
public:
    Element(std::string prefix, std::string input);
    ~Element();

    std::string getName();
    void setName(std::string value);

    std::vector<Element *> getElementsByTagName(std::string name);
    std::string getAttribute(std::string key);
    std::string getTextContent();
};

class Text: public Element {
private:
    std::string content;
public:
    Text(std::string name, std::string value);
    std::string textContent();
};

#endif

#ifndef namespace_hpp
#define namespace_hpp

class Namespace {
private:
    std::string name;
    Element * root;
public:
    Namespace(std::string name, std::string data);
    ~Namespace();
    std::string getName();
    std::vector<Element *> getElementsByTagName(std::string name);
};

#endif

#ifndef document_hpp
#define document_hpp

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

#ifndef prolog_hpp
#define prolog_hpp

class Prolog {
private:
    void parse(std::string data);
public:
    Prolog(std::string data);
};

#endif

#ifndef xml_hpp
#define xml_hpp

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

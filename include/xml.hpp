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
    std::string prefix;
    std::string name;
    std::vector<Attribute> attributes;
    std::vector<Element *> children;

    void parse(std::string input);
public:
    Element(std::string input);
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
    Text(std::string value);
    std::string textContent();
};

#endif

#ifndef document_hpp
#define document_hpp

class Document {
private:
    Element * root;
public:
    Document(std::string input);
    ~Document();
    std::vector<Element *> getElementsByTagName(std::string name);
};

#endif

#ifndef xml_hpp
#define xml_hpp

class Xml {
private:
    std::string version;
    std::string encoding;
    std::string standalone;

    Document * document;

    void parse(std::string input);
public:
    Xml(std::string input);
    ~Xml();
    Document * getDocument();
};

#endif

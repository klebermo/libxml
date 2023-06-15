#include <string>
#include <vector>

class SyntaxTree;

class XPath {
private:
    SyntaxTree *syntaxTree;
public:
    XPath();
    ~XPath();

    void parse(std::string expression);
    XML * evaluate(std::string value);
};

class XQuery {
private:
    SyntaxTree *syntaxTree;
public:
    XQuery();
    ~XQuery();

    void parse(std::string query);
    XML * execute(std::string value);
};

class Tag {
public:
    Tag();
    virtual ~Tag() = 0;

    virtual void addChild(Tag * child) = 0;
    virtual void addAtributo(Tag * atributo) = 0;

    virtual void parse(std::string xml_string) = 0;
    virtual std::string toString() = 0;
};

class Declaration : public Tag {
private:
    std::string version;
    std::string encoding;
public:
    Declaration();
    ~Declaration();

    std::string getVersion();
    void setVersion(std::string version);

    std::string getEncoding();
    void setEncoding(std::string encoding);

    void addChild(Tag * child);
    void addAtributo(Tag * atributo);

    void parse(std::string xml_string);
    std::string toString();
};

class DocType : public Tag {
private:
    std::string name;
    std::string id;
public:
    DocType();
    ~DocType();

    std::string getName();
    void setName(std::string name);

    std::string getId();
    void setId(std::string id);

    void addChild(Tag * child);
    void addAtributo(Tag * atributo);

    void parse(std::string xml_string);
    std::string toString();
};

class Comentario : public Tag {
private:
    std::string value;
public:
    Comentario();
    ~Comentario();

    std::string getValue();
    void setValue(std::string value);

    void addChild(Tag * child);
    void addAtributo(Tag * atributo);

    void parse(std::string xml_string);
    std::string toString();
};

class Data : public Tag {
private:
    std::string value;
public:
    Data();
    ~Data();

    std::string getValue();
    void setValue(std::string value);

    void addChild(Tag * child);
    void addAtributo(Tag * atributo);

    void parse(std::string xml_string);
    std::string toString();
};

class Atributo {
private:
    std::string key;
    std::string value;
public:
    Atributo(std::string key, std::string value);

    std::string getKey();
    void setKey(std::string key);
    
    std::string getValue();
    void setValue(std::string value);

    std::string operator[](std::string key);

    void parse(std::string xml_string);
    std::string toString();
};

class Elemento : public Tag {
private:
    std::string key;
    std::string value;
    std::vector<Atributo> atributos;
    std::vector<Elemento> children;
public:
    Elemento();
    ~Elemento();

    std::string getKey();
    void setKey(std::string key);

    std::string getValue();
    void setValue(std::string value);

    std::vector<Atributo> getAtributos();
    void setAtributos(std::vector<Atributo> atributos);
    void addAtributo(Tag * atributo);

    std::vector<Elemento> getChildren();
    void setChildren(std::vector<Elemento> children);
    void addChild(Tag * child);

    Elemento * get(std::string key);
    std::string get_value(std::string key);

    void parse(std::string xml_string);
    std::string toString();
};

class XML {
private:
    Tag * root;
public:
    XML();
    ~XML();

    Tag * getRoot();

    void parse(std::string xml_string);
    std::string toString();

    void parseFile(std::string file_path);
    Tag * operator[](std::string key);
};

std::string_view ltrim(std::string_view str);
std::string_view rtrim(std::string_view str);
std::string_view trim(std::string_view str);

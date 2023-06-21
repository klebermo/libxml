#include <string>
#include <vector>

class Tag {
public:
    Tag();
    virtual ~Tag() = 0;

    virtual void addChild(Tag * child) = 0;
    virtual void addAtributo(Tag * atributo) = 0;

    virtual void parse(std::string xml_string) = 0;
    virtual std::string toString() = 0;
};

class Atributo : public Tag {
private:
    std::string key;
    std::string value;
public:
    Atributo();
    Atributo(std::string key, std::string value);
    ~Atributo();

    std::string getKey();
    void setKey(std::string key);
    
    std::string getValue();
    void setValue(std::string value);

    void addChild(Tag * child);
    void addAtributo(Tag * atributo);

    void parse(std::string xml_string);
    std::string toString();
};

class Elemento : public Tag {
protected:
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

    std::vector<Elemento> getChildren();
    void setChildren(std::vector<Elemento> children);

    Elemento * get(std::string key);
    std::string get_value(std::string key);

    void addChild(Tag * child);
    void addAtributo(Tag * atributo);

    void parse(std::string xml_string);
    std::string toString();
};

class Declaration : public Elemento {
private:
    std::string version;
    std::string encoding;
public:
    Declaration();
    ~Declaration() override;

    std::string getVersion();
    void setVersion(std::string version);

    std::string getEncoding();
    void setEncoding(std::string encoding);

    void parse(std::string xml_string) override;
    std::string toString() override;
};

class Data : public Elemento {
private:
    std::string value;
public:
    Data();
    ~Data() override;

    std::string getValue();
    void setValue(std::string value);

    void parse(std::string xml_string) override;
    std::string toString() override;
};

class DocType : public Elemento {
private:
    std::string name;
    std::string id;
public:
    DocType();
    ~DocType() override;

    std::string getName();
    void setName(std::string name);

    std::string getId();
    void setId(std::string id);

    void parse(std::string xml_string) override;
    std::string toString() override;
};

class Comentario : public Elemento {
private:
    std::string value;
public:
    Comentario();
    ~Comentario() override;

    std::string getValue();
    void setValue(std::string value);

    void parse(std::string xml_string) override;
    std::string toString() override;
};

class XML {
private:
    Declaration * root;
public:
    XML();
    ~XML();

    Tag * getRoot();

    void parse(std::string xml_string);
    std::string toString();

    void parseFile(std::string file_path);

    void evaluateXPath(std::string expression);
    void evaluateXQuery(std::string expression);
};

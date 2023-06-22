#ifndef declaration_hpp
#define declaration_hpp

#include "element.hpp"

class Document : public Element {
private:
    std::string version;
    std::string encoding;
public:
    Document();
    ~Document() override;

    std::string getVersion();
    void setVersion(std::string version);

    std::string getEncoding();
    void setEncoding(std::string encoding);

    void parse(std::string xml_string) override;
    std::string toString() override;
};

#endif

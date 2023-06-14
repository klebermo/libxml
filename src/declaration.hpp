#ifndef declaration_hpp
#define declaration_hpp

#include "elemento.hpp"

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

#endif

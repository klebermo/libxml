#ifndef comentario
#define comentario

#include "element.hpp"

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

#endif

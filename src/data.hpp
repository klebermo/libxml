#ifndef data_hpp
#define data_hpp

#include "elemento.hpp"

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

#endif

#include "data.hpp"

Data::Data() {}

Data::~Data() {}

std::string Data::getValue() {
    return this->value;
}

void Data::setValue(std::string value) {
    this->value = value;
}

void Data::parse(std::string xml_string) {
    std::string tag_start = "<![CDATA[";
    std::string tag_end = "]]>";

    int value_start = xml_string.find(tag_start) + tag_start.length();
    int value_end = xml_string.find(tag_end);

    std::string value = xml_string.substr(value_start, value_end - value_start);

    setValue(value);
}

std::string Data::toString() {
    return "<![CDATA[" + this->value + "]]>";
}

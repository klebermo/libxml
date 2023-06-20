#include "comment.hpp"

Comentario::Comentario() {}

Comentario::~Comentario() {}

std::string Comentario::getValue() {
    return this->value;
}

void Comentario::setValue(std::string value) {
    this->value = value;
}

void Comentario::parse(std::string xml_string) {
    std::string tag_start = "<!--";
    std::string tag_end = "-->";

    int value_start = xml_string.find(tag_start) + tag_start.length();
    int value_end = xml_string.find(tag_end);

    std::string value = xml_string.substr(value_start, value_end - value_start);

    setValue(value);
}

std::string Comentario::toString() {
    return "<!--" + this->value + "-->";
}

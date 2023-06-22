#include "comment.hpp"

Comment::Comment() {}

Comment::~Comment() {}

std::string Comment::getValue() {
    return this->value;
}

void Comment::setValue(std::string value) {
    this->value = value;
}

void Comment::parse(std::string xml_string) {
    std::string tag_start = "<!--";
    std::string tag_end = "-->";

    int value_start = xml_string.find(tag_start) + tag_start.length();
    int value_end = xml_string.find(tag_end);

    std::string value = xml_string.substr(value_start, value_end - value_start);

    setValue(value);
}

std::string Comment::toString() {
    return "<!--" + this->value + "-->";
}

#include "text.hpp"

Text::Text() {
    //
}

Text::~Text() {
    //
}

std::string Text::getName() {
    return this->name;
}

void Text::setName(std::string name) {
    this->name = name;
}

std::string Text::getValue() {
    return this->value;
}

void Text::setValue(std::string value) {
    this->value = value;
}

void Text::parse(std::string xml_string) {
    //
}

std::string Text::toString() {
    return "";
}

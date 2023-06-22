#include "attribute.hpp"

Attribute::Attribute() {
    //
}

Attribute::Attribute(std::string key, std::string value) {
    this->key = key;
    this->value = value;
}

Attribute::~Attribute() {
    //
}

std::string Attribute::getKey() {
    return this->key;
}

void Attribute::setKey(std::string key) {
    this->key = key;
}

std::string Attribute::getValue() {
    return this->value;
}

void Attribute::setValue(std::string value) {
    this->value = value;
}

void Attribute::addChild(Tag * child) {
    //
}

void Attribute::addAttribute(Tag * atributo) {
    //
}

void Attribute::parse(std::string xml_string) {
    int key_start = xml_string.find_first_not_of(' ');
    int key_end = xml_string.find_first_of('=', key_start);

    std::string key = xml_string.substr(key_start, key_end - key_start);

    int value_start = xml_string.find_first_of('"', key_end);
    int value_end = xml_string.find_first_of('"', value_start + 1);

    std::string value = xml_string.substr(value_start + 1, value_end - value_start - 1);

    setKey(key);
    setValue(value);
}

std::string Attribute::toString() {
    return this->key + "=\"" + this->value + "\"";
}

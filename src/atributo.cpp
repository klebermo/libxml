#include "atributo.hpp"

Atributo::Atributo() {
    //
}

Atributo::Atributo(std::string key, std::string value) {
    this->key = key;
    this->value = value;
}

Atributo::~Atributo() {
    //
}

std::string Atributo::getKey() {
    return this->key;
}

void Atributo::setKey(std::string key) {
    this->key = key;
}

std::string Atributo::getValue() {
    return this->value;
}

void Atributo::setValue(std::string value) {
    this->value = value;
}

void Atributo::addChild(Tag * child) {
    //
}

void Atributo::addAtributo(Tag * atributo) {
    //
}

void Atributo::parse(std::string xml_string) {
    int key_start = xml_string.find_first_not_of(' ');
    int key_end = xml_string.find_first_of('=', key_start);

    std::string key = xml_string.substr(key_start, key_end - key_start);

    int value_start = xml_string.find_first_of('"', key_end);
    int value_end = xml_string.find_first_of('"', value_start + 1);

    std::string value = xml_string.substr(value_start + 1, value_end - value_start - 1);

    setKey(key);
    setValue(value);
}

std::string Atributo::toString() {
    return this->key + "=\"" + this->value + "\"";
}

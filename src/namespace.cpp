#include "namespace.hpp"

Namespace::Namespace() {
    //
}

Namespace::~Namespace() {
    //
}

std::string Namespace::getName() {
    return name;
}

void Namespace::setName(std::string name) {
    this->name = name;
}

std::string Namespace::getValue() {
    return value;
}

void Namespace::setValue(std::string value) {
    this->value = value;
}

void Namespace::parse(std::string xml_string) {
    //
}

std::string Namespace::toString() {
    return "";
}



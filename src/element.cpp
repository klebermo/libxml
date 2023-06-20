#include "element.hpp"

Elemento::Elemento() {}

Elemento::~Elemento() {}

std::string Elemento::getKey() {
    return this->key;
}

void Elemento::setKey(std::string key) {
    this->key = key;
}

std::string Elemento::getValue() {
    return this->value;
}

void Elemento::setValue(std::string value) {
    this->value = value;
}

std::vector<Atributo> Elemento::getAtributos() {
    return this->atributos;
}

void Elemento::setAtributos(std::vector<Atributo> atributos) {
    this->atributos = atributos;
}

std::vector<Elemento> Elemento::getChildren() {
    return this->children;
}

void Elemento::setChildren(std::vector<Elemento> children) {
    this->children = children;
}

Elemento * Elemento::get(std::string key) {
    for(std::vector<Elemento>::size_type i = 0; i < this->children.size(); i++) {
        if(this->children[i].getKey() == key) {
            return &this->children[i];
        }
    }
    return nullptr;
}

std::string Elemento::get_value(std::string key) {
    for(std::vector<Atributo>::size_type i = 0; i < this->atributos.size(); i++) {
        if(this->atributos[i].getKey() == key) {
            return this->atributos[i].getValue();
        }
    }
    return "";
}

void Elemento::addChild(Tag * child) {
    Elemento * elem = (Elemento *) child;
    this->children.push_back(*elem);
}

void Elemento::addAtributo(Tag * atributo) {
    Atributo * attr = (Atributo *) atributo;
    this->atributos.push_back(*attr);
}

void Elemento::parse(std::string xml_string) {
    int open_tag_start = xml_string.find_first_of('<');
    int open_tag_end = xml_string.find_first_of('>', open_tag_start);
    std::string open_tag = xml_string.substr(open_tag_start, open_tag_end - open_tag_start + 1);

    int key_start = open_tag.find_first_not_of("<", open_tag_start);
    int key_end;
    if(open_tag.find(" ") != std::string::npos) {
        key_end = open_tag.find_first_of(' ', open_tag_start);
    } else {
        key_end = open_tag.find_first_of('>', open_tag_start);
    }
    std::string key = xml_string.substr(key_start, key_end - key_start);
    setKey(key);

    int close_tag_start = xml_string.find("</" + key);
    int close_tag_end = xml_string.find_first_of('>', close_tag_start);
    std::string close_tag = xml_string.substr(close_tag_start, close_tag_end - close_tag_start + 1);

    if(open_tag.length() > key.length()) {
        int atributo_start = xml_string.find_first_not_of(' ', key_end);
        int atributo_end = xml_string.find_first_of('>', atributo_start);
        std::string atributos = xml_string.substr(atributo_start, atributo_end - atributo_start);

        std::string attr;
        for(std::string::size_type i=0; i<atributos.length(); i++) {
            if(atributos[i] == ' ' || i == atributos.length() - 1) {
                Atributo * atributo = new Atributo();
                atributo->parse(attr);
                addAtributo(atributo);
                attr = "";
            } else {
                attr += atributos[i];
            }
        }
    }

    if(close_tag_start - open_tag_end > 1) {
        int value_start = xml_string.find_first_not_of(' ', open_tag_end);
        int value_end = xml_string.find_first_of('<', value_start);
        std::string value = xml_string.substr(value_start + 1, value_end - value_start - 1);
        setValue(value);
    }
}

std::string Elemento::toString() {
    std::string xml_string = "<" + getKey();

    for(std::vector<Atributo>::size_type i = 0; i < this->atributos.size(); i++) {
        xml_string += " " + this->atributos[i].toString();
    }

    xml_string += ">";

    xml_string += getValue();

    for(std::vector<Elemento>::size_type i = 0; i < this->children.size(); i++) {
        xml_string += this->children[i].toString();
    }

    xml_string += getValue() + "</" + getKey() + ">";

    return xml_string;
}

#include "element.hpp"

Element::Element() {}

Element::~Element() {}

std::string Element::getKey() {
    return this->key;
}

void Element::setKey(std::string key) {
    this->key = key;
}

std::string Element::getValue() {
    return this->value;
}

void Element::setValue(std::string value) {
    this->value = value;
}

std::vector<Attribute> Element::getAttributes() {
    return this->attributes;
}

void Element::setAttributes(std::vector<Attribute> attributes) {
    this->attributes = attributes;
}

std::vector<Element> Element::getChildren() {
    return this->children;
}

void Element::setChildren(std::vector<Element> children) {
    this->children = children;
}

Element * Element::get(std::string key) {
    for(std::vector<Element>::size_type i = 0; i < this->children.size(); i++) {
        if(this->children[i].getKey() == key) {
            return &this->children[i];
        }
    }
    return nullptr;
}

std::string Element::get_value(std::string key) {
    for(std::vector<Attribute>::size_type i = 0; i < this->attributes.size(); i++) {
        if(this->attributes[i].getKey() == key) {
            return this->attributes[i].getValue();
        }
    }
    return "";
}

void Element::addChild(Tag * child) {
    Element * elem = (Element *) child;
    this->children.push_back(*elem);
}

void Element::addAttribute(Tag * attribute) {
    Attribute * attr = (Attribute *) attribute;
    this->attributes.push_back(*attr);
}

void Element::parse(std::string xml_string) {
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
        int attribute_start = xml_string.find_first_not_of(' ', key_end);
        int attribute_end = xml_string.find_first_of('>', attribute_start);
        std::string attributes = xml_string.substr(attribute_start, attribute_end - attribute_start);

        std::string attr;
        for(std::string::size_type i=0; i<attributes.length(); i++) {
            if(attributes[i] == ' ' || i == attributes.length() - 1) {
                Attribute * attribute = new Attribute();
                attribute->parse(attr);
                addAttribute(attribute);
                attr = "";
            } else {
                attr += attributes[i];
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

std::string Element::toString() {
    std::string xml_string = "<" + getKey();

    for(std::vector<Attribute>::size_type i = 0; i < this->attributes.size(); i++) {
        xml_string += " " + this->attributes[i].toString();
    }

    xml_string += ">";

    xml_string += getValue();

    for(std::vector<Element>::size_type i = 0; i < this->children.size(); i++) {
        xml_string += this->children[i].toString();
    }

    xml_string += getValue() + "</" + getKey() + ">";

    return xml_string;
}

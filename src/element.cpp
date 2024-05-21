#include "element.hpp"

Element::Element() {
    //
}

Element::Element(std::string data) {
    //
}

std::list<Element> Element::getElementsByTagName(std::string name) {
    std::list<Element> result;

    for(Element item : this->children) {
        if(item.getName().compare(name) == 0) {
            result.emplace_back(item);
        }
    }

    return result;
}

std::string Element::getName() {
    return this->name;
}

void Element::setName(std::string value) {
    this->name = value;
}

std::map<std::string, std::string> Element::get_attributes() {
    return this->attributes;
}

void Element::add_attribute(std::string key, std::string value) {
    this->attributes.emplace(key, value);
}

void Element::add_child(Element child) {
    Element element;

    element.setName(child.getName());
    for(auto item : child.get_attributes()) {
        element.add_attribute(item.first, item.second);
    }

    children.push_back(element);
}

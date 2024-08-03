#include "element.hpp"

Attribute::Attribute(std::string input) {
    this->parse(input);
}

Attribute::Attribute(std::string key, std::string value) {
    this->key = key;
    this->value = value;
}

std::string Attribute::getKey() {
    return this->key;
}

std::string Attribute::getValue() {
    return this->value;
}

void Attribute::parse(std::string data) {
    std::regex attributeHandler("(\\w+)=([\"'])(.*?)\\2|\\w+");
    auto attrsBegin = std::sregex_iterator(data.begin(), data.end(), attributeHandler);
    auto attrsEnd = std::sregex_iterator();

    for (std::sregex_iterator i = attrsBegin; i != attrsEnd; ++i) {
        std::smatch attrMatch = *i;
        this->key = attrMatch[1].str();
        this->value = attrMatch[3].matched ? attrMatch[3].str() : attrMatch[2].str();
    }
}

Element::Element(std::string input) {
    this->parse(input);
}

Element::~Element() {
    this->name.clear();
    this->attributes.clear();
    this->children.clear();
}

std::string Element::getName() {
    return this->name;
}

void Element::setName(std::string value) {
    this->name = value;
}

std::string Element::getAttribute(std::string key) {
    for(Attribute attribute : attributes) {
        if(attribute.getKey().compare(key) == 0) {
            return attribute.getValue();
        }
    }
    return "";
}

std::vector<Element *> Element::getElementsByTagName(std::string name) {
    std::vector<Element *> result;

    for(Element * item : this->children) {
        if(name == item->getName()) {
            result.push_back(item);
        }
    }

    return result;
}

void Element::parse(std::string input) {
    std::regex expressionHandler("<(\\w+)((?:\\s+\\w+=(?:\"[^\"]*\"|\\w+))*)\\s*(?:>([\\s\\S]*?)</\\1>|/>)");
    std::smatch matches;

    while (std::regex_search(input, matches, expressionHandler)) {
        std::string tagName = matches[1].str();
        std::string attributesStr = matches[2].str();
        std::string innerContent = matches[3].matched ? matches[3].str() : "";
        this->name = tagName;

        std::regex attributeHandler("(\\w+)=([\"'])(.*?)\\2|\\w+");
        auto attrsBegin = std::sregex_iterator(attributesStr.begin(), attributesStr.end(), attributeHandler);
        auto attrsEnd = std::sregex_iterator();

        for (std::sregex_iterator i = attrsBegin; i != attrsEnd; ++i) {
            std::smatch attrMatch = *i;
            std::string key = attrMatch[1].str();
            std::string value = attrMatch[3].matched ? attrMatch[3].str() : attrMatch[2].str();
            this->attributes.push_back(Attribute(key, value));
        }

        if (!innerContent.empty()) {
            std::regex nestedTagHandler("<(\\w+)((?:\\s+\\w+=(?:\"[^\"]*\"|\\w+))*)\\s*(?:>([\\s\\S]*?)</\\1>|/>)");
            std::smatch nestedMatches;

            while (std::regex_search(innerContent, nestedMatches, nestedTagHandler)) {
                std::string content = nestedMatches[0].str();

                if(content.find("<") != std::string::npos) {
                    Element * node = new Element(content);
                    this->children.push_back(node);
                } else {
                    Text * node = new Text(content);
                    this->children.push_back(node);
                }

                innerContent = nestedMatches.suffix().str();
            }
        }

        input = matches.suffix().str();
    }
}

Text::Text(std::string value) : Element(value) {
    this->content = value;
}

std::string Text::textContent() {
    return this->content;
}

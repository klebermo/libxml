#include "element.hpp"

Element::Element() {
    this->name = "";
}

Element::Element(std::string input) {
    this->name = "";
    this->parse(this, input);
}

Element::Element(Element * node, std::string input) {
    this->parse(node, input);
}

void Element::add_child(Element * node) {
    children.push_back(node);
}

std::string Element::getName() {
    return this->name;
}

void Element::setName(std::string value) {
    this->name = value;
}

std::string Element::getAttributeValue(std::string key) {
    return this->attributes[key];
}

void Element::setAttribute(std::string key, std::string value) {
    this->attributes[key] = value;
}

Element Element::getElementByTagName(std::string name) {
    std::vector<Element> values = this->getElementsByTagName(name);
    if(values.empty()) {
        return Element();
    } else {
        return values[0];
    }
}

std::vector<Element> Element::getElementsByTagName(std::string name) {
    std::vector<Element> result;

    for(Element * item : this->children) {
        if(item->getName().compare(name) == 0) {
            result.push_back(*item);
        }
    }

    return result;
}

Element Element::innerHTML() {
    return Element();
}

std::string Element::innerText() {
    return "";
}

void Element::parse(Element * node, std::string input) {
    std::regex expressionHandler("<(\\w+)((?:\\s+\\w+=(?:\"[^\"]*\"|\\w+))*)\\s*(?:>(.*?)</\\1>|/>)");
    std::smatch matches;

    while (std::regex_search(input, matches, expressionHandler)) {
        std::string tagName = matches[1].str();
        std::string attributesStr = matches[2].str();
        std::string innerContent = matches[3].matched ? matches[3].str() : "";

        Element* child = new Element();
        child->setName(tagName);

        std::cout << "name: " << child->getName() << std::endl;
        std::cout << "attributes: " << attributesStr << std::endl;
        std::cout << "innerContent: " << innerContent << std::endl;

        std::regex attributeHandler("(\\w+)=([\"'])(.*?)\\2|\\w+");
        auto attrsBegin = std::sregex_iterator(attributesStr.begin(), attributesStr.end(), attributeHandler);
        auto attrsEnd = std::sregex_iterator();

        for (std::sregex_iterator i = attrsBegin; i != attrsEnd; ++i) {
            std::smatch attrMatch = *i;
            std::string key = attrMatch[1].str();
            std::string value = attrMatch[3].matched ? attrMatch[3].str() : attrMatch[2].str();
            child->setAttribute(key, value);
        }

        if (!innerContent.empty()) {
            std::regex innerExpressionHandler("<(\\w+)((?:\\s+\\w+=(?:\"[^\"]*\"|\\w+))*)\\s*(?:>(.*?)</\\1>|/>)");
            std::smatch innerMatches;
            std::string remainingContent = innerContent;

            while (std::regex_search(remainingContent, innerMatches, innerExpressionHandler)) {
                Element* innerChild = new Element();
                innerChild->parse(innerChild, innerMatches[0].str());
                child->add_child(innerChild);

                remainingContent = innerMatches.suffix().str();
            }

            if (!remainingContent.empty()) {
                Text* textNode = new Text(remainingContent);
                child->add_child(textNode);
            }
        }

        node->add_child(child);

        input = matches.suffix().str();
    }
}

Text::Text() {
    this->content = "";
}

Text::Text(std::string value) {
    this->content = value;
}

std::string Text::getContent() {
    return this->content;
}

void Text::setContent(std::string value) {
    this->content = value;
}

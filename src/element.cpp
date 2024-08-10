#include "element.hpp"

Attribute::Attribute(std::string input) {
    this->parse(input);
}

Attribute::Attribute(std::string key, simpleType * value) {
    this->key = key;
    this->value = value;
}

std::string Attribute::getKey() {
    return this->key;
}

simpleType * Attribute::getValue() {
    return this->value;
}

void Attribute::parse(std::string data) {
    std::regex attributeHandler("(\\w+)=([\"'])(.*?)\\2|\\w+");
    auto attrsBegin = std::sregex_iterator(data.begin(), data.end(), attributeHandler);
    auto attrsEnd = std::sregex_iterator();

    for (std::sregex_iterator i = attrsBegin; i != attrsEnd; ++i) {
        std::smatch attrMatch = *i;
        this->key = attrMatch[1].str();
        std::string value = attrMatch[3].matched ? attrMatch[3].str() : attrMatch[2].str();
    }
}

Element::Element() {
    name = "";
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

simpleType * Element::getAttribute(std::string key) {
    for(Attribute attribute : attributes) {
        if(attribute.getKey().compare(key) == 0) {
            return attribute.getValue();
        }
    }
    return nullptr;
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

        auto pos = tagName.find(":");
        if(pos == std::string::npos) {
            this->name = tagName;
        } else {
            std::string prefix = tagName.substr(0, pos);
            this->name = tagName.substr(pos + 1, tagName.length());
        }

        std::regex attributeHandler("(\\w+)=([\"'])(.*?)\\2|\\w+");
        auto attrsBegin = std::sregex_iterator(attributesStr.begin(), attributesStr.end(), attributeHandler);
        auto attrsEnd = std::sregex_iterator();

        for (std::sregex_iterator i = attrsBegin; i != attrsEnd; ++i) {
            std::smatch attrMatch = *i;
            std::string key = attrMatch[1].str();
            std::string value_str = attrMatch[3].matched ? attrMatch[3].str() : attrMatch[2].str();

            Type type = get_type(value_str);
            simpleType * value_data;
            switch(type) {
                case string:
                    value_data = new String();
                    break;
                case duration:
                    value_data = new Duration();
                    break;
                case dateTime:
                    value_data = new Datetime();
                    break;
                case time_:
                    value_data = new Time();
                    break;
                case date_:
                    value_data = new Date();
                    break;
                case yearMonth:
                    value_data = new YearMonth();
                    break;
                case year:
                    value_data = new Year();
                    break;
                case monthDay:
                    value_data = new MonthDay();
                    break;
                case day:
                    value_data = new Day();
                    break;
                case month:
                    value_data = new Month();
                    break;                                            
            };
            *value_data << value_str;
            this->attributes.push_back(Attribute(key, value_data));
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
    //
}

std::string Text::textContent() {
    return "";
}

Data::Data(std::string value) {
    //
}

std::string Data::getContent() {
    return "";
}

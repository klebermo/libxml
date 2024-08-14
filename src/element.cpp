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
        std::string data = attrMatch[3].matched ? attrMatch[3].str() : attrMatch[2].str();

        Type type = get_type(data);
        switch(type) {
            case string:
                this->value = new String();
                break;
            case duration:
                this->value = new Duration();
                break;
            case dateTime:
                this->value = new Datetime();
                break;
            case time_:
                this->value = new Time();
                break;
            case date_:
                this->value = new Date();
                break;
            case yearMonth:
                this->value = new YearMonth();
                break;
            case year:
                this->value = new Year();
                break;
            case monthDay:
                this->value = new MonthDay();
                break;
            case day:
                this->value = new Day();
                break;
            case month:
                this->value = new Month();
                break;                                            
        };
        *this->value << data;
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
        if(name.compare(item->getName()) == 0) {
            result.push_back(item);
        }
    }

    return result;
}

Element * Element::innerHTML() {
    return this;
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
            std::string value = attrMatch[3].matched ? attrMatch[3].str() : attrMatch[2].str();
            
            std::string data = key + "=" + value;
            this->attributes.push_back(Attribute(data));
        }

        if (!innerContent.empty()) {
            std::regex nestedTagHandler(
                R"(<(\w+)((?:\s+\w+=(?:\"[^\"]*\"|\w+))*)\s*(?:>([\s\S]*?)<\/\1>|\/>)|([\s\S]+?)(?=<|$))"
            );
            std::smatch nestedMatches;

            while (std::regex_search(innerContent, nestedMatches, nestedTagHandler)) {
                std::string content = nestedMatches[0].str();

                if(content.find("<") != std::string::npos) {
                    Element * node = new Tag(content);
                    this->children.push_back(node);
                } else if(content.find("CDATA") != std::string::npos) {
                    Data * node = new Data(content);
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

Tag::Tag(std::string value) {
    this->parse(value);
}

Tag::~Tag() {
    //
}

std::string Tag::textContent() {
    std::string result;
    for(Element * item : this->children) {
        result = result + item->textContent();
    }
    return result;
}

Text::Text(std::string value) : Element(value) {
    std::istringstream ss(value);
    std::string token;
    while(ss >> token) {
        simpleType * type = new String();
        type->read(token);
        content.push_back(type);
    }
}

Text::~Text() {
    //
}

std::string Text::textContent() {
    std::string value;
    for(simpleType * type : content) {
        value = value + type->print() + " ";
    }
    return value;
}

Data::Data(std::string value) {
    this->content = value;
}

Data::~Data() {
    //
}

std::string Data::textContent() {
    return this->content;
}

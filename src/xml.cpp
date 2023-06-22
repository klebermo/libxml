#include "xml.hpp"

#include <fstream>

XML::XML() {
    this->root = nullptr;
}

XML::~XML() {
    delete this->root;
}

Tag * XML::getRoot() {
    return this->root;
}

void XML::parse(std::string xml_string) {
    std::string::size_type pos = 0;
    for(;pos < xml_string.size();) {
        int tag_start = xml_string.find_first_of("<", pos);
        int tag_end = xml_string.find_first_of(">", tag_start);

        std::string tag = xml_string.substr(tag_start, tag_end - tag_start + 1);

        char first = tag[1];
        char second = tag[2];

        if(first == '?') {
            Document * decl = new Document();
            decl->parse(tag);
            this->root = decl;
        } else if(first == '!') {
            if(second == '-') {
                Comment * comment = new Comment();
                comment->parse(tag);
                this->root->addChild(comment);
            } else if(second == '[') {
                Data * data = new Data();
                data->parse(tag);
                this->root->addChild(data);
            } else if(second == 'D') {
                DocType * type = new DocType();
                type->parse(tag);
                this->root->addChild(type);
            }
        } else if(first == '/') {
            //
        } else {
            int nome_start = tag.find_first_not_of("<");
            int nome_end;
            if(tag.find(" ") != std::string::npos) {
                nome_end = tag.find_first_of(" ", nome_start);
            } else {
                nome_end = tag.find_first_of(">", nome_start);
            }
            std::string key = tag.substr(nome_start, nome_end - nome_start);

            int close_tag_start = xml_string.find("</" + key + ">");
            int close_tag_end = xml_string.find(">", close_tag_start);
            std::string close_tag = xml_string.substr(close_tag_start, close_tag_end - close_tag_start + 1);

            int value_start = xml_string.find_first_not_of(">", tag_end);
            int value_end = close_tag_start - 1;
            std::string value = xml_string.substr(value_start, value_end - value_start);

            tag += value + close_tag;

            Element * elem = new Element();
            elem->parse(tag);
            this->root->addChild(elem);
        }

        pos = tag_end + 1;
    }
}

std::string XML::toString() {
    return this->root->toString();
}

void XML::parseFile(std::string file_name) {
    std::ifstream file(file_name, std::ios::in);

    if(!file.is_open()) {
        return;
    }

    std::string xml_string, line;

    while(std::getline(file, line)) {
        xml_string += trim(line);
    }

    parse(xml_string);
}

void XML::evaluateXPath(std::string expression) {
    XPath * path = new XPath();
    path->parse(expression);
    path->evaluate();
}

void XML::evaluateXQuery(std::string expression) {
    XQuery * query = new XQuery();
    query->parse(expression);
    query->evaluate();
}

std::string_view ltrim(std::string_view str)
{
    const auto pos(str.find_first_not_of(" \t\n\r\f\v"));
    str.remove_prefix(std::min(pos, str.length()));
    return str;
}

std::string_view rtrim(std::string_view str)
{
    const auto pos(str.find_last_not_of(" \t\n\r\f\v"));
    str.remove_suffix(std::min(str.length() - pos - 1, str.length()));
    return str;
}

std::string_view trim(std::string_view str)
{
    str = ltrim(str);
    str = rtrim(str);
    return str;
}

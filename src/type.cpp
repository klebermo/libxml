#include "type.hpp"

DocType::DocType() {}

DocType::~DocType() {}

std::string DocType::getName() {
    return this->name;
}

void DocType::setName(std::string name) {
    this->name = name;
}

std::string DocType::getId() {
    return this->id;
}

void DocType::setId(std::string id) {
    this->id = id;
}

void DocType::parse(std::string xml_string) {
    std::string tag_start = "<!DOCTYPE ";
    std::string tag_end = ">";

    int name_start = xml_string.find(tag_start) + tag_start.length();
    int name_end = xml_string.find(" ", name_start);
    std::string name = xml_string.substr(name_start, name_end - name_start);

    int id_start = xml_string.find(" ", name_end) + 1;
    int id_end = xml_string.find(tag_end);
    std::string id = xml_string.substr(id_start, id_end - id_start);

    setName(name);
    setId(id);
}

std::string DocType::toString() {
    std::string xml_string = "<!DOCTYPE " + this->name;

    if (this->id != "") {
        xml_string += " " + this->id;
    }

    xml_string += ">";

    return xml_string;
}
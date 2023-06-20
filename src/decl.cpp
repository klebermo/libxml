#include "decl.hpp"

Declaration::Declaration() {
    this->version = "1.0";
    this->encoding = "UTF-8";
}

Declaration::~Declaration() {}

std::string Declaration::getVersion() {
    return this->version;
}

void Declaration::setVersion(std::string version) {
    this->version = version;
}

std::string Declaration::getEncoding() {
    return this->encoding;
}

void Declaration::setEncoding(std::string encoding) {
    this->encoding = encoding;
}

void Declaration::parse(std::string xml_string) {
    std::string tag_start = "<?xml";
    std::string tag_end = "?>";

    int value_start = xml_string.find(tag_start) + tag_start.length();
    int value_end = xml_string.find(tag_end);
    std::string value = xml_string.substr(value_start, value_end - value_start);

    std::string version_start = "version=\"";
    std::string version_end = "\"";
    int version_start_index = value.find(version_start) + version_start.length();
    int version_end_index = value.find(version_end, version_start_index);
    std::string version = value.substr(version_start_index, version_end_index - version_start_index);

    std::string encoding_start = "encoding=\"";
    std::string encoding_end = "\"";
    int encoding_start_index = value.find(encoding_start) + encoding_start.length();
    int encoding_end_index = value.find(encoding_end, encoding_start_index);
    std::string encoding = value.substr(encoding_start_index, encoding_end_index - encoding_start_index);

    setVersion(version);
    setEncoding(encoding);
}

std::string Declaration::toString() {
    std::string result = "<?xml version=\"" + this->version + "\" encoding=\"" + this->encoding;

    for(Atributo atributo : this->atributos) {
        result += " " + atributo.toString();
    }

    result += "\"?>";

    for(Elemento child : this->children) {
        result += child.toString();
    }

    return result;
}

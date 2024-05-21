#include "text.hpp"

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


#include "string.hpp"

std::string String::print() {
    std::string result;
    result = result + preffix;
    for(char ch : value.tokens)
        result = result + ch;
    result = result + suffix;
    return result;
}

void String::read(std::string data) {
    char ch;
    std::string punctuation = ",;:()\"—!?.";
    std::stringstream is(data);

    preffix = 0x0;
    suffix = 0x0;

    if (punctuation.find(is.peek()) != std::string::npos) {
        is >> ch;
        preffix = ch;
    }

    while (punctuation.find(is.peek()) == std::string::npos) {
        is >> ch;
        value.tokens.push_back(ch);
    }

    if (punctuation.find(is.peek()) != std::string::npos) {
        is >> ch;
        suffix = ch;
    }
}

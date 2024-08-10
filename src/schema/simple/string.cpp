#include "string.hpp"

std::ostream& String::print(std::ostream& os) {
    os << str();
    return os;
}

std::istream& String::read(std::istream& is) {
    char ch;
    std::string punctuation = ",;:()\"—!?."; // Pontuações válidas
    value.tokens.clear();

    // Ler e identificar o prefixo
    is >> ch;
    if (punctuation.find(ch) != std::string::npos) {
        switch (ch) {
            case ',':
                preffix = Virgula;
                break;
            case ';':
                preffix = Ponto_e_virgula;
                break;
            case ':':
                preffix = Dois_pontos;
                break;
            case '(':
                preffix = Parenteses_abertura;
                break;
            case ')':
                preffix = Parenteses_fechamento;
                break;
            case '"':
                preffix = Aspas;
                break;
            case '-':
                preffix = Travessao;
                break;
            case '!':
                preffix = Ponto_de_exclamacao;
                break;
            case '?':
                preffix = Ponto_de_interrogacao;
                break;
            case '.':
                if(is.peek() == '.')
                    preffix = Reticencias;
                else
                    preffix = Ponto_final;
                break;
        }
    } else {
        is.setstate(std::ios::failbit); // Sinalizar erro de leitura
        return is;
    }

    // Ler a palavra
    while (is >> std::noskipws >> ch && ch != ' ' && punctuation.find(ch) == std::string::npos) {
        value.tokens.push_back(ch);
    }

    // Identificar o sufixo ou espaço no final
    if (punctuation.find(ch) != std::string::npos) {
        switch (ch) {
            case ',':
                suffix = Virgula;
                break;
            case ';':
                suffix = Ponto_e_virgula;
                break;
            case ':':
                suffix = Dois_pontos;
                break;
            case '(':
                suffix = Parenteses_abertura;
                break;
            case ')':
                suffix = Parenteses_fechamento;
                break;
            case '"':
                suffix = Aspas;
                break;
            case '-':
                suffix = Travessao;
                break;
            case '!':
                suffix = Ponto_de_exclamacao;
                break;
            case '?':
                suffix = Ponto_de_interrogacao;
                break;
            case '.':
                if(is.peek() == '.')
                    suffix = Reticencias;
                else
                    suffix = Ponto_final;
                break;
        }
    } else {
        is.setstate(std::ios::failbit); // Sinalizar erro de leitura
    }

    return is;
}

std::string String::str() {
    return std::string(value.tokens.data());
}

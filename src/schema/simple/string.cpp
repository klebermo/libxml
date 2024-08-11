#include "string.hpp"

std::string String::print() {
    std::string result;
    switch(preffix) {
        case Zero: result = result + ""; break;
        case Virgula: result = result + ","; break;
        case Ponto_e_virgula: result = result + ";"; break;
        case Dois_pontos: result = result + ":"; break;
        case Reticencias: result = result + "..."; break;
        case Parenteses_abertura: result = result + "("; break;
        case Parenteses_fechamento: result = result + ")"; break;
        case Aspas: result = result + "\""; break;
        case Travessao: result = result + "-"; break;
        case Ponto_de_exclamacao: result = result + "!"; break;
        case Ponto_de_interrogacao: result = result + "?"; break;
        case Ponto_final: result = result + "."; break;
    }
    result = result + value.tokens.data();
    switch(suffix) {
        case Zero: result = result + ""; break;
        case Virgula: result = result + ","; break;
        case Ponto_e_virgula: result = result + ";"; break;
        case Dois_pontos: result = result + ":"; break;
        case Reticencias: result = result + "..."; break;
        case Parenteses_abertura: result = result + "("; break;
        case Parenteses_fechamento: result = result + ")"; break;
        case Aspas: result = result + "\""; break;
        case Travessao: result = result + "-"; break;
        case Ponto_de_exclamacao: result = result + "!"; break;
        case Ponto_de_interrogacao: result = result + "?"; break;
        case Ponto_final: result = result + "."; break;
    }    
    return result;
}

void String::read(std::string data) {
    char ch;
    std::string punctuation = ",;:()\"—!?.";
    value.tokens.clear();

    // Ler e identificar o prefixo
    std::stringstream is(data);
    if (punctuation.find(is.peek()) != std::string::npos) {
        is >> ch;
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
            default:
                preffix = Zero;
                break;
        }
    }

    // Ler a palavra
    while (is >> ch && ch != ' ' && punctuation.find(ch) == std::string::npos) {
        value.tokens.push_back(ch);
    }

    // Identificar o sufixo ou espaço no final
    if (punctuation.find(is.peek()) != std::string::npos) {
        is >> ch;
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
            default:
                suffix = Zero;
                break;
        }
    }
}

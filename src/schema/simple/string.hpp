#ifndef string_hpp
#define string_hpp

#include "../simple.hpp"

enum Pontuacao {
    Zero,
    Virgula,
    Ponto_e_virgula,
    Dois_pontos,
    Reticencias,
    Parenteses_abertura,
    Parenteses_fechamento,
    Aspas,
    Travessao,
    Ponto_de_exclamacao,
    Ponto_de_interrogacao,
    Ponto_final
};

struct Word {
    std::vector<char> tokens;
};

class String : public simpleType {
private:
    enum Pontuacao preffix;
    struct Word value;
    enum Pontuacao suffix;
public:
    std::string print();
    void read(std::string data);
};

#endif

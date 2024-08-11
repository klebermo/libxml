#ifndef string_hpp
#define string_hpp

#include "../simple.hpp"

struct Word {
    std::vector<char> tokens;
};
typedef struct Word Word;

class String : public simpleType {
private:
    char preffix;
    Word value;
    char suffix;
public:
    std::string print();
    void read(std::string data);
};

#endif

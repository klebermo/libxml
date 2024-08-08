#ifndef string_hpp
#define string_hpp

#include "../simple.hpp"

class String : public simpleType {
private:
    std::string value;
public:
    std::ostream& print(std::ostream& os);
    std::istream& read(std::istream& is);
    std::string str();
};

#endif

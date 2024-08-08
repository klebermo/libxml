#ifndef duration_hpp
#define duration_hpp

#include "../simple.hpp"

class Duration : public simpleType {
private:
    long value;
public:
    std::ostream& print(std::ostream& os);
    std::istream& read(std::istream& is);
    std::string str();
};

#endif

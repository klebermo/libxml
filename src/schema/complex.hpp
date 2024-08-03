#ifndef complex_hpp
#define complex_hpp

#include "any.hpp"

class complexType : public Any {
private:
    //
public:
    complexType * get();
    void set(complexType * value);
    complexType * parse(std::string value);
};

#endif

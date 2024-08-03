#ifndef any_hpp
#define any_hpp

#include <string>
#include <list>
#include <map>
#include <vector>
#include <regex>
#include <iostream>

class Any {
public:
    virtual Any * get() = 0;
    virtual void set(Any * value) = 0;
    virtual Any * parse(std::string value) = 0;
};

#endif

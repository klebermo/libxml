#ifndef any_hpp
#define any_hpp

#include <string>
#include <list>
#include <map>
#include <vector>
#include <regex>

class Any {
public:
    virtual std::string print() = 0;
    virtual void read(std::string value) = 0;
};

#endif

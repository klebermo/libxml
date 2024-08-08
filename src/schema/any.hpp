#ifndef any_hpp
#define any_hpp

#include <string>
#include <list>
#include <map>
#include <vector>
#include <regex>

class Any {
public:
    virtual std::ostream& print(std::ostream& os) = 0;
    virtual std::istream& read(std::istream& is) = 0;
    virtual std::string str() = 0;
};

#endif

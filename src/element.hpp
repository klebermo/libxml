#ifndef element_hpp
#define element_hpp

#include "schema/simple/date_time.hpp"
#include "schema/simple/date.hpp"
#include "schema/simple/day.hpp"
#include "schema/simple/duration.hpp"
#include "schema/simple/month_day.hpp"
#include "schema/simple/month.hpp"
#include "schema/simple/string.hpp"
#include "schema/simple/time.hpp"
#include "schema/simple/year_month.hpp"
#include "schema/simple/year.hpp"

#include "schema/complex.hpp"

class Attribute {
private:
    std::string key;
    simpleType * value;

    void parse(std::string data);
public:
    Attribute(std::string data);
    Attribute(std::string key, simpleType * value);

    std::string getKey();
    simpleType * getValue();
};

class Element {
private:
    std::string name;
    std::vector<Attribute> attributes;
    std::vector<Element *> children;

    void parse(std::string input);
public:
    Element();
    Element(std::string input);
    ~Element();

    std::string getName();
    void setName(std::string value);

    std::vector<Element *> getElementsByTagName(std::string name);
    simpleType * getAttribute(std::string key);
};

class Text: public Element {
private:
    std::vector<simpleType *> content;
public:
    Text(std::string value);
    std::string textContent();
};

class Data: public Element {
private:
    std::string content;
public:
    Data(std::string value);
    std::string getContent();
};

#endif

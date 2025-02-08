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

#ifndef simple_hpp
#define simple_hpp

enum Type {
    string,
    duration,
    dateTime,
    time_,
    date_,
    yearMonth,
    year,
    monthDay,
    day,
    month
};

Type get_type(std::string value);

class simpleType : public Any {
public:
    friend void operator<<(simpleType& type, std::string value) {
        type.read(value);
    }
};

#endif

#ifndef string_hpp
#define string_hpp

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

#ifndef duration_hpp
#define duration_hpp

class Duration : public simpleType {
private:
    long value;
public:
    std::string print();
    void read(std::string data);
};

#endif

#ifndef date_hpp
#define date_hpp

class Date : public simpleType {
private:
    u_int32_t value;
public:
    std::string print();
    void read(std::string data);

    u_int8_t day();
    u_int8_t month();
    u_int16_t year();
};

#endif

#ifndef time_hpp
#define time_hpp

class Time : public simpleType {
private:
    u_int32_t value;
public:
    std::string print();
    void read(std::string data);

    u_int8_t hour();
    u_int8_t minute();
    u_int8_t second();
};

#endif

#ifndef date_time_hpp
#define date_time_hpp

class Datetime : public simpleType {
private:
    u_int64_t value;
public:
    std::string print();
    void read(std::string value);

    u_int8_t day();
    u_int8_t month();
    u_int16_t year();
    u_int8_t hour();
    u_int8_t minute();
    u_int8_t second();
};

#endif

#ifndef year_month_hpp
#define year_month_hpp

class YearMonth : public simpleType {
private:
    char value[6];
public:
    std::string print();
    void read(std::string data);
};

#endif

#ifndef year_hpp
#define year_hpp

class Year : public simpleType {
private:
    char value[2];
public:
    std::string print();
    void read(std::string data);
};

#endif

#ifndef month_day_hpp
#define month_day_hpp

class MonthDay : public simpleType {
private:
    char value[4];
public:
    std::string print();
    void read(std::string data);
};

#endif

#ifndef month_hpp
#define month_hpp

class Month : public simpleType {
private:
    char value[2];
public:
    std::string print();
    void read(std::string data);
};

#endif

#ifndef day_hpp
#define day_hpp

class Day : public simpleType {
private:
    char value[2];
public:
    std::string print();
    void read(std::string data);
};

#endif

#ifndef any_hpp
#define any_hpp

#include "element.hpp"

enum Type {
    //
};

enum PrimitiveType {
    duration,
    dataTime,
    time,
    date,
    gYearMonth,
    gYear,
    gMonthDay,
    gDay,
    gMonth,
    boolean,
    base64Binary,
    hexBinary,
    float_number,
    decimal,
    double_number,
    anyURI,
    QName,
    Notation,
    string
};

enum Token {
    language,
    name,
    NMTOKEN,
    ID,
    IDREF,
    ENTITY
};

enum DecimalType {
    negativeInteger,
    int_number,
    short_number,
    byte,
    unsignedLong,
    unsignedInt,
    unsignedShort,
    unsignedByte,
    positiveInteger
};

class Any {
private:
    //
public:
    //
};

class AnySimpleType : public Any {
private:
    Type type;
    std::any value;
public:
    //
};

class AnyComplexType : public Any {
private:
    Any * root;
public:
    //
};

#endif

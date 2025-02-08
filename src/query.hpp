#ifndef query_hpp
#define query_hpp

#include "path.hpp"

class Expression {
public:
    virtual std::string  evaluate() = 0;
};

class Literal : public Expression {
private:
    std::string value;
public:
    Literal(const std::string& val) : value(val) {}
    std::string evaluate();
};

class Variable : public Expression {
private:
    std::string name;
    std::string value;
public:
    Variable(const std::string& name, const std::string& value) : name(name), value(value) {}
    std::string evaluate();
};

class PathExpr : public Expression {
private:
    std::vector<std::string> steps;
public:
    PathExpr(std::string value);
    std::string evaluate();
};

class Condition : public Expression {
private:
    std::string operand1;
    char op;
    std::string operand2;
public:
    Condition();
    Condition(std::string value);
    std::string evaluate();
};

class Function : public Expression {
private:
    std::string name;
    std::vector<Expression> arguments;
public:
    Function(std::string value);
    std::string evaluate();
};

class Loop : public Expression {
private:
    Condition condition;
    std::vector<Expression> expressions;
public:
    Loop(std::string value);
    std::string evaluate();
};

class Query {
private:
    std::vector<Expression> expressions;
public:
    Query(std::string value);
    void evaluate();
};

#endif

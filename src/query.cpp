#include "query.hpp"

Query::Query(std::string value) {
    //
}

void Query::evaluate() {
    //
}

std::string Literal::evaluate() {
    return value;
}

std::string Variable::evaluate() {
    return "";
}

PathExpr::PathExpr(std::string value) {
    //
}

std::string PathExpr::evaluate() {
    return "";
}

Condition::Condition(std::string value) {
    //
}

std::string Condition::evaluate() {
    return "";
}

Function::Function(std::string value) {
    //
}

std::string Function::evaluate() {
    return "";
}

Loop::Loop(std::string value) {
    //
}

std::string Loop::evaluate() {
    return "";
}

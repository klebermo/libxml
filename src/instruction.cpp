#include "instruction.hpp"

Instruction::Instruction() {
    //
}

Instruction::~Instruction() {
    //
}

std::string Instruction::getName() {
    return name;
}

void Instruction::setName(std::string name) {
    this->name = name;
}

std::string Instruction::getValue() {
    return value;
}

void Instruction::setValue(std::string value) {
    this->value = value;
}

void Instruction::parse(std::string xml_string) {
    //
}

std::string Instruction::toString() {
    return "";
}

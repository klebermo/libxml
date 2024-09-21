#include "function.hpp"

Function::~Function() {
    for(auto arg : arguments) delete arg;
}

#include "Operator.h"
#include "../Exceptions/Exceptions.h"

void UnaryOperator::checkNum() {
    if (numArgs.size() != 1 or not strArgs.empty())
        throw IncorrectAmountOfArgumentsException();
}

void UnaryOperator::checkStr() {
    if (strArgs.size() != 1 or not numArgs.empty())
        throw IncorrectAmountOfArgumentsException();
}
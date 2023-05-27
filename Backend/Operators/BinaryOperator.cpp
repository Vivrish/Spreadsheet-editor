#include "Operator.h"
#include "../Exceptions/Exceptions.h"


void BinaryOperator::checkStr() {
    if (not (strArgs.size() == 2 and numArgs.empty()))
        throw IncorrectAmountOfArgumentsException();
}

void BinaryOperator::checkNum() {
    if (not (numArgs.size() == 2 and strArgs.empty()))
        throw IncorrectAmountOfArgumentsException();
}
#include "Operator.h"
#include "../Exceptions/Exceptions.h"

double Multiply::calculateNum() {
    BinaryOperator::checkNum();
    double output = numArgs[0] * numArgs[1];
    return output;
}

std::string Multiply::calculateStrNum() {
    if (not (numArgs.size() == 1 and strArgs.size() == 1))
        throw IncorrectAmountOfArgumentsException();
    std::string output;
    for (int i = 0; i < numArgs[0]; i++)
        output += strArgs[0];
    clear();
    return output;
}

std::string Multiply::calculateStr() {
    if (numArgs.size() == 1 and strArgs.size() == 1)
        return calculateStrNum();
    throw InvalidOperationException();
}

Multiply::Multiply() {
    associativity = Associativity::LEFT;
    precedence = 3;
    signature  = "*";
}

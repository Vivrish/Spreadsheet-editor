#include "Operator.h"
#include "../Exceptions/Exceptions.h"

double Multiply::calculateNum() {
    BinaryOperator::checkNum();
    std::cout << numArgs[0] << "*" << numArgs[1] << std::endl;
    double output = numArgs[0] * numArgs[1];
    return output;
}

std::string Multiply::calculateStrNum() {
    if (not(numArgs.size() == 1 and strArgs.size() == 1))
        throw IncorrectAmountOfArgumentsException();
    std::string output;
    output += "\"";
    for (int i = 0; i < numArgs[0]; i++) {
        output += strArgs[0].substr(1, strArgs[0].length() - 2);
    }
    output += "\"";
    clear();
    return output;
}

std::string Multiply::calculateStr() {
    if (numArgs.size() == 1 and strArgs.size() == 1)
        return calculateStrNum();
    else throw InvalidOperationException();
}

Multiply::Multiply() {
    associativity = Associativity::LEFT;
    precedence = 3;
    signature = "*";
}

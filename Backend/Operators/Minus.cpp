#include "Operator.h"
#include "../Exceptions/Exceptions.h"

std::string Minus::calculateStr() {
    if (not numArgs.empty() or strArgs.size() != 2)
        throw InvalidOperationException();

    std::string output = strArgs[0].substr(1, strArgs[0].length() - 2);

    size_t position = output.find(strArgs[1].substr(1, strArgs[1].length() - 2));

    if (position != std::string::npos)
        output.erase(position, strArgs[1].length() - 2);

    return "\"" + output + "\"";
}

double Minus::calculateNum() {
    BinaryOperator::checkNum();
    std::cout << numArgs[0] << "-" << numArgs[1] << std::endl;
    double output = numArgs[0] - numArgs[1];
    clear();
    return output;
}

Minus::Minus() {
    signature  = "-";
    associativity = Associativity::LEFT;
    precedence = 2;
}
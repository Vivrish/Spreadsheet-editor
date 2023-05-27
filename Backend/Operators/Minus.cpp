#include "Operator.h"
#include "../Exceptions/Exceptions.h"

std::string Minus::calculateStr() {
    if (not numArgs.empty() or strArgs.size() != 2)
        throw InvalidOperationException();

    std::string output = strArgs[0];

    size_t position = output.find(strArgs[1]);

    if (position != std::string::npos)
        output.erase(position);

    return output;
}

double Minus::calculateNum() {
    BinaryOperator::checkNum();
    double output = numArgs[0] - numArgs[1];
    clear();
    return output;
}
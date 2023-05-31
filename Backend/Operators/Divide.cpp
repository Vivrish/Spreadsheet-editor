#include "Operator.h"
#include "../Exceptions/Exceptions.h"


std::string Divide::calculateStr() {
    if (not numArgs.empty() or strArgs.size() != 2)
        throw InvalidOperationException();

    std::string output = strArgs[0];

    size_t position = output.find(strArgs[1]);

    while (position != std::string::npos) {
        output.erase(position, strArgs[1].length());
        position = output.find(strArgs[1]);
    }

    return output;
}

double Divide::calculateNum() {
    BinaryOperator::checkNum();
    double output = numArgs[0] / numArgs[1];
    return output;
}

Divide::Divide() {
    associativity = Associativity::LEFT;
    precedence = 3;
    signature  = "/";
}
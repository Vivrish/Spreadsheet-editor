#include "Operator.h"

double Plus::calculateNum() {
    BinaryOperator::checkNum();
    double output = numArgs[0] + numArgs[1];
    clear();
    return output;
}

std::string Plus::calculateStr() {
    BinaryOperator::checkStr();
    std::string output = strArgs[0] + strArgs[1];
    return output;
}

Plus::Plus() {
    signature  = "+";
    associativity = Associativity::LEFT;
    precedence = 2;
}
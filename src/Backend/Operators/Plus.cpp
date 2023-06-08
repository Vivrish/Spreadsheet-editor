#include "Operator.h"


double Plus::calculateNum() {
    BinaryOperator::checkNum();
//    std::cout << numArgs[0] << "+" << numArgs[1] << std::endl;
    double output = numArgs[0] + numArgs[1];
    clear();
    return output;
}

std::string Plus::calculateStr() {
    BinaryOperator::checkStr();
    std::string output = strArgs[0].substr(0, strArgs[0].length() - 1) + strArgs[1].substr(1, strArgs[1].length());
//    std::cout << strArgs[0].substr(0, strArgs[0].length() - 1) << " + " << strArgs[1].substr(1, strArgs[1].length()) << std::endl;
    return output;
}

Plus::Plus() {
    signature  = "+";
    associativity = Associativity::LEFT;
    precedence = 2;
}
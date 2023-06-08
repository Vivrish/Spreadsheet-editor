#include "Operator.h"
#include <cmath>

double Power::calculateNum() {
    BinaryOperator::checkNum();
//    std::cout << numArgs[0] << "^" << numArgs[1] << std::endl;
    double output = pow(numArgs[0], numArgs[1]);
    return output;
}

Power::Power() {
    signature  = "^";
    associativity = Associativity::RIGHT;
    precedence = 4;
}
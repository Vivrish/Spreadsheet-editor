#include "Formula.h"
#include <cmath>

Cos::Cos(): Formula() {
    signature = "cos";
}

double Cos::calculateNum() {
    UnaryOperator::checkNum();
    double output = cos(numArgs[0]);
    return output;
}
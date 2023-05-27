#include "Formula.h"
#include <cmath>

double Cos::calculateNum() {
    UnaryOperator::checkNum();
    double output = cos(numArgs[0]);
    return output;
}
#include "Formula.h"
#include <cmath>

double Sin::calculateNum() {
    UnaryOperator::checkNum();
    double output = sin(numArgs[0]);
    return output;
}
#include "Formula.h"
#include <cmath>

Sin::Sin(): Formula(){
    signature = "sin";
}

double Sin::calculateNum() {
    UnaryOperator::checkNum();
    double output = sin(numArgs[0]);
    return output;
}
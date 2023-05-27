#include "Operator.h"
#include "../Exceptions/Exceptions.h"
#include <cmath>

double Power::calculateNum() {
    BinaryOperator::checkNum();
    double output = pow(numArgs[0], numArgs[1]);
    return output;
}

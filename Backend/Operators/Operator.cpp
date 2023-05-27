#include "Operator.h"
#include "../Exceptions/Exceptions.h"
void Operator::addArgument(double argument) {
    numArgs.push_back(argument);
}

void Operator::addArgument(const std::string &argument) {
    strArgs.push_back(argument);
}

std::string Operator::calculateStr() {
    throw InvalidOperationException();
}

double Operator::calculateNum() {
    throw InvalidOperationException();
}

void Operator::clear() {
    numArgs.clear();
    strArgs.clear();
}
#include "Operator.h"
#include "../Exceptions/Exceptions.h"


// todo move to util

bool isNum(const std::string &input) {
    if (input == "-")
        return false;
    for (size_t i = 0; i < input.size(); i++) {
        if (i == 0) {
            if (input[i] != '-' and not isdigit(input[i]))
                return false;
        } else if (not isdigit(input[i]))
            return false;
    }
    return true;
}

void Operator::addArgument(double argument) {
    // Reverse order
    numArgs.insert(numArgs.begin(), argument);
}

void Operator::addArgument(const std::string &argument) {
    // Reverse order
    if (isNum(argument))
        numArgs.insert(numArgs.begin(), stod(argument));
    else
        strArgs.insert(strArgs.begin(), argument);
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

std::string Operator::getSignature() const {
    return signature;
}

Associativity Operator::getAssociativity() const {
    return associativity;
}

int Operator::getPrecedence() const {
    return precedence;
}
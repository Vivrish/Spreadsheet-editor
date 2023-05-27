#ifndef SEMESTRALWORK_FORMULA_H
#define SEMESTRALWORK_FORMULA_H

#include "../Operators/Operator.h"
#include "../CellData/Cell.h"

class Formula: public UnaryOperator {
public:
    std::string calculateStr() override = 0;
    double calculateNum() override = 0;
protected:
    Associativity associativity = Associativity::RIGHT;
    int precedence = 4;
};

class Sin: public UnaryOperator {
    double calculateNum() final;
protected:
    std::string signature  = "sin";
};

class Cos: public UnaryOperator {
    double calculateNum() final;
protected:
    std::string signature  = "cos";
};

class Strip: public UnaryOperator {
    std::string calculateStr() final;
protected:
    std::string signature  = "strip";
};

#endif //SEMESTRALWORK_FORMULA_H

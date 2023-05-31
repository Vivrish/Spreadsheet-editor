#ifndef SEMESTRALWORK_FORMULA_H
#define SEMESTRALWORK_FORMULA_H

#include "../Operators/Operator.h"

class Formula: public UnaryOperator {
public:
    Formula();
};

class Sin: public Formula {
public:
    Sin();
    double calculateNum() final;
};

class Cos: public Formula {
public:
    Cos();
    double calculateNum() final;
};

class Strip: public Formula {
public:
    Strip();
    std::string calculateStr() final;
};

#endif //SEMESTRALWORK_FORMULA_H

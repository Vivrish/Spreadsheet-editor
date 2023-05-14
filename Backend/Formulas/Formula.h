#ifndef SEMESTRALWORK_FORMULA_H
#define SEMESTRALWORK_FORMULA_H

#include "../Operators/Operator.h"
#include "../CellData/Cell.h"
class Formula: public UnaryOperator {
    String calculateStr() override = 0;
    Numeric calculateNum() override = 0;
};

class Sin: public UnaryOperator {
    String calculateStr() final;
    Numeric calculateNum() final;
};

class Cos: public UnaryOperator {
    String calculateStr() final;
    Numeric calculateNum() final;
};

class Strip: public UnaryOperator {
    String calculateStr() final;
    Numeric calculateNum() final;
};

class CellReference: public UnaryOperator {
    String calculateStr() final;
    Numeric calculateNum() final;

private:
    Cell* cellPointer;
};
#endif //SEMESTRALWORK_FORMULA_H

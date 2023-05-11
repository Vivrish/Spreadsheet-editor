#ifndef SEMESTRALWORK_FORMULA_H
#define SEMESTRALWORK_FORMULA_H
#include "../CellDataType.h"
#include "../StoredData.h"

class Formula: public CellDataType{
public:
    virtual CellDataType evaluate() = 0;

    CellDataType * getValue() override = 0;

    StoredData returnType = StoredData::Unknown;
};

class Sin: public Formula {
public:
    StoredData returnType = StoredData::Number;

    Sin(double pArgument);

    CellDataType evaluate() override;

    CellDataType * getValue() final;
private:
    double argument;
};


#endif //SEMESTRALWORK_FORMULA_H

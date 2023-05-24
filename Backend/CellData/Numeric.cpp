#include "CellDataType.h"

using namespace std;

Numeric::Numeric(const std::string &pValue): CellDataType(pValue) {}

void Numeric::evaluate() {
    result = stringParser.parseAsNumeric();
}

shared_ptr<CellDataType> Numeric::getCopy() {
    return make_shared<Numeric>(*this);
}
#include "CellDataType.h"

using namespace std;

Numeric::Numeric(const std::string &pValue): CellDataType(pValue) {}

void Numeric::evaluate() {
    stringParser.parseAsNumeric(rawValue);
    result = stringParser.getResult();
}

shared_ptr<CellDataType> Numeric::getCopy() {
    return make_shared<Numeric>(*this);
}
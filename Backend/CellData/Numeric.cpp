#include "CellDataType.h"


Numeric::Numeric(const std::string &pValue): CellDataType(pValue) {}

void Numeric::evaluate() {
    result = stringParser.parseAsNumeric();
}
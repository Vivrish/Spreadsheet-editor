#include "CellDataType.h"

using namespace std;

Numeric::Numeric(const std::string &pValue): CellDataType(pValue) {}

void Numeric::evaluate() {
    stringParser.parse(evaluatedRefsValue);
    result = to_string(stringParser.getAST()->getNumericResult());
}

shared_ptr<CellDataType> Numeric::getCopy() {
    return make_shared<Numeric>(*this);
}
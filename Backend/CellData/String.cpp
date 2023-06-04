#include "CellDataType.h"

using namespace std;

String::String(const std::string &pValue): CellDataType(pValue) {}

void String::evaluate() {
    stringParser.parse(rawValue);
    result = stringParser.getAST()->getStringResult();
}

shared_ptr<CellDataType> String::getCopy() {
    return make_shared<String>(*this);
}
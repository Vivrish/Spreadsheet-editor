#include "CellDataType.h"

using namespace std;

String::String(const std::string &pValue): CellDataType(pValue) {}

void String::evaluate() {
    result = stringParser.parseAsString(rawValue);
}

shared_ptr<CellDataType> String::getCopy() {
    return make_shared<String>(*this);
}
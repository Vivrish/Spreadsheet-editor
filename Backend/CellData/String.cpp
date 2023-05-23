#include "CellDataType.h"

String::String(const std::string &pValue): CellDataType(pValue) {}

void String::evaluate() {
    result = stringParser.parseAsString(rawValue);
}
#include "CellDataType.h"


CellDataType::CellDataType(const std::string &pValue) {
    rawValue = pValue;
}

std::string CellDataType::getRawValue() const {
    return rawValue;
}

std::string CellDataType::getResult() const {
    return result;
}

void CellDataType::setRawValue(const std::string &val) {
    rawValue = val;
}
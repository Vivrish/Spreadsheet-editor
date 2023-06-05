#include "CellDataType.h"
#include "../Exceptions/Exceptions.h"

using namespace std;

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

std::shared_ptr<CellDataType> CellDataType::generateType(CellDataTypes type) {
    if (type == CellDataTypes::NUMERIC)
        return make_shared<Numeric>();
    return make_shared<String>();
}

CellDataTypes CellDataType::strToTypes(const std::string &input) {
    if (input == "numeric")
        return CellDataTypes::NUMERIC;
    else if (input == "string")
        return CellDataTypes::STRING;
    throw TypeDoesNotExistException();
}
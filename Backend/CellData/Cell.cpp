#include "Cell.h"


using namespace std;

Cell::Cell(int row, int column) {
    position.first = row;
    position.second = column;
    value = make_shared<String>("");
    formatType = make_shared<PureString>("");
}

Cell::Cell(int row, int column, const std::shared_ptr<CellDataType> & pValue) {
    position.first = row;
    position.second = column;
    value = pValue;
    formatType = make_shared<PureString>(pValue->getRawValue());
}

void Cell::setFormat(const std::shared_ptr<FormatType> & newFormat) {
    formatType = newFormat;
}

std::string Cell::getOutput() const {
    return formatType->getFormattedValue();
}

void Cell::formatExpression() {
    formatType->format();
}

void Cell::evaluateExpression() {
    value->evaluate();
    formatType->setValue(value->getResult());
}

void Cell::setType(const std::shared_ptr<CellDataType> &newType) {
    value = newType;
}

void Cell::setValue(const std::string &val) {
    value->setRawValue(val);
    formatType->setValue(val);
}

void Cell::clear() {
    value->setRawValue("");
    formatType = make_shared<PureString>("");
    type = StoredData::Unknown;
    output = "";
}

std::string Cell::getRawOutput() const {
    return value->getRawValue();
}

std::string Cell::getCalculated() const {
    return value->getResult();
}


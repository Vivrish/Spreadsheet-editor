#include "Cell.h"

#include <utility>


using namespace std;


Cell::Cell(int row, int column, const std::shared_ptr<CellDataType> & pValue) {
    position.first = row;
    position.second = column;
    value = pValue;
    formatType = make_shared<FormatType>(pValue->getRawValue());
    //todo
    // How do I fix this?
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

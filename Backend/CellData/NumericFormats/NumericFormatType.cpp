#include <stdexcept>
#include "../FormatType.h"
#include "../../Exceptions/Exceptions.h"

using namespace std;

NumericFormatType::NumericFormatType(const std::string &pRawValue): FormatType(pRawValue) {
    try {
        rawNumericValue = stod(rawValue);
    }
    catch (invalid_argument &) {
        throw FormatDataMismatchException();
    }
}

void NumericFormatType::setValue(const std::string &val) {
    rawValue = val;
    try {
        rawNumericValue = stod(rawValue);
    }
    catch (invalid_argument &) {
        throw FormatDataMismatchException();
    }
}
#include "../FormatType.h"

NumericFormatType::NumericFormatType(const std::string &pRawValue): FormatType(pRawValue) {
    rawNumericValue = std::stod(rawValue);
}
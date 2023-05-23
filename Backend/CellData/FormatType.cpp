#include "FormatType.h"

FormatType::FormatType(const std::string &pRawValue) {
    rawValue = pRawValue;
}

std::string FormatType::getFormattedValue() const {
    return rawValue;
}
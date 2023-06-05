#include "../FormatType.h"

using namespace std;

NumericFormatType::NumericFormatType(const std::string &pRawValue): FormatType(pRawValue) {
    rawNumericValue = stod(rawValue);
}

void NumericFormatType::setValue(const std::string &val) {
    rawValue = val;
    rawNumericValue = stod(val);
}
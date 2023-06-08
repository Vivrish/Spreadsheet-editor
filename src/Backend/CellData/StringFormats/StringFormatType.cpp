#include "../FormatType.h"


StringFormatType::StringFormatType(const std::string & pRawValue): FormatType(pRawValue) {}


void StringFormatType::setValue(const std::string &val) {
    rawValue = val;
}
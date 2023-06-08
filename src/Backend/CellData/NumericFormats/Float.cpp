#include "../FormatType.h"

using namespace std;


Float::Float(const std::string &pRawValue): NumericFormatType(pRawValue) {}

void Float::format() {
    formattedValue = std::to_string(rawNumericValue);
}

std::shared_ptr <FormatType> Float::getCopy() {
    return make_shared<Float>(*this);
}
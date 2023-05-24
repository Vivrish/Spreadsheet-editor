#include "../FormatType.h"

using namespace std;

Boolean::Boolean(const std::string &pRawValue): NumericFormatType(pRawValue) {}

void Boolean::format() {
    if (rawNumericValue != 0)
        formattedValue = "true";
    else
        formattedValue = "false";
}

shared_ptr<FormatType> Boolean::getCopy() {
    return make_shared<Boolean>(*this);
}
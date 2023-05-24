#include "../FormatType.h"

using namespace std;

PureString::PureString(const std::string &pRawValue): StringFormatType(pRawValue) {}

void PureString::format() {
    formattedValue = rawValue;
}

shared_ptr<FormatType> PureString::getCopy() {
    return make_shared<PureString>(*this);
}
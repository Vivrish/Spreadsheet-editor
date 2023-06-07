#include "../FormatType.h"


using namespace std;

PadRightString::PadRightString(const std::string &pRawValue): StringFormatType(pRawValue) {}

void PadRightString::format() {
    formattedValue = rawValue + constants["PADDING"];
}

shared_ptr<FormatType> PadRightString::getCopy() {
    return make_shared<PadRightString>(*this);
}
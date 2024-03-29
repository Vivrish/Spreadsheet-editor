#include "../FormatType.h"


using namespace std;

PadLeftString::PadLeftString(const std::string &pRawValue): StringFormatType(pRawValue) {}

void PadLeftString::format() {
    formattedValue = constants["PADDING"] + rawValue;
}

shared_ptr<FormatType> PadLeftString::getCopy() {
    return make_shared<PadLeftString>(*this);
}
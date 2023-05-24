#include <algorithm>
#include "../FormatType.h"

using namespace std;

StrippedString::StrippedString(const std::string &pRawValue): StringFormatType(pRawValue) {}

void StrippedString::format() {
    formattedValue = rawValue;

    formattedValue.erase(formattedValue.begin(), std::find_if(formattedValue.begin(), formattedValue.end(), [](unsigned char ch) {
        return !std::isspace(ch);
    }));

    formattedValue.erase(std::find_if(formattedValue.rbegin(), formattedValue.rend(), [](unsigned char ch) {
        return !std::isspace(ch);
    }).base(), formattedValue.end());

}

shared_ptr<FormatType> StrippedString::getCopy() {
    return make_shared<StrippedString>(*this);
}
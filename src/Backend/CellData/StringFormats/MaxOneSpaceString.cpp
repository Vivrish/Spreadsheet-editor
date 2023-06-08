#include "../FormatType.h"

using namespace std;

MaxOneSpaceString::MaxOneSpaceString(const std::string &pRawValue): StringFormatType(pRawValue) {}

void MaxOneSpaceString::format() {
    bool prevSpace = false;

    for (char letter: rawValue) {
        if (isspace(letter)) {
            if (not prevSpace)
                formattedValue.push_back(letter);
            prevSpace = true;
        }
        else {
            formattedValue.push_back(letter);
            prevSpace = false;
        }
    }
}

shared_ptr<FormatType> MaxOneSpaceString::getCopy() {
    return make_shared<MaxOneSpaceString>(*this);
}
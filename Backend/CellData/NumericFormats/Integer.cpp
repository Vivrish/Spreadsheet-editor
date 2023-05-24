#include "../FormatType.h"
#include <cmath>

using namespace std;

Integer::Integer(const std::string &pRawValue): NumericFormatType(pRawValue) {}

void Integer::format() {
    formattedValue = std::to_string(floor(rawNumericValue));
}

std::shared_ptr<FormatType> Integer::getCopy() {
    return make_shared<Integer>(*this);
}
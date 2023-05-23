#include "../FormatType.h"
#include <cmath>

void Integer::format() {
    formattedValue = std::to_string(floor(rawNumericValue));
}
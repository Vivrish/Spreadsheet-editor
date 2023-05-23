#include "../FormatType.h"


void Boolean::format() {
    if (rawNumericValue != 0)
        formattedValue = "true";
    else
        formattedValue = "false";
}
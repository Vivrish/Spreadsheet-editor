#include "../FormatType.h"
#include <cmath>
#include <string>
#include "../../Exceptions/Exceptions.h"

void Time::format() {
    int result = (int) floor(rawNumericValue);
    int hours = result / 3600;
    result -= 3600 * hours;
    int minutes = result / 60;
    result -= 60 * minutes;
    int seconds = result;
    if (result < 0 or hours < 0 or minutes < 0 or seconds < 0)
        throw IncorrectCalculationException();
    formattedValue = std::to_string(hours) + ":" + std::to_string(minutes) + ":" + std::to_string(seconds);
}
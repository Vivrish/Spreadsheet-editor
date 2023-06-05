#include "../FormatType.h"
#include <ctime>
#include <chrono>
#include "../../Exceptions/Exceptions.h"
using namespace std;

Date::Date(const std::string &pRawValue): NumericFormatType(pRawValue) {}

void Date::format() {
    if (rawNumericValue < 0 or rawNumericValue > 75000)
        throw InvalidDateException();
    chrono::system_clock::time_point start(chrono::hours(0));
    start += chrono::hours(24) * (int)rawNumericValue;
    time_t time = chrono::system_clock::to_time_t(start);
    tm * date = gmtime(&time);
    formattedValue += to_string(date->tm_mday) + "/" + to_string(date->tm_mon + 1) + "/" + to_string(date->tm_year + 1900);
}

std::shared_ptr<FormatType> Date::getCopy() {
    return make_shared<Date>(*this);
}
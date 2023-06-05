#include "FormatType.h"
#include "../Exceptions/Exceptions.h"

using namespace std;

FormatType::FormatType(const std::string &pRawValue) {
    rawValue = pRawValue;
}

std::string FormatType::getFormattedValue() const {
    return formattedValue;
}

std::shared_ptr<FormatType> FormatType::generateType(const FormatTypes &type) {
    if (type == FormatTypes::BOOLEAN)
        return make_shared<Boolean>();
    else if (type == FormatTypes::DATE)
        return make_shared<Date>();
    else if (type == FormatTypes::FLOAT)
        return make_shared<Float>();
    else if (type == FormatTypes::INTEGER)
        return make_shared<Integer>();
    else if (type == FormatTypes::TIME)
        return make_shared<Time>();
    else if (type == FormatTypes::MAX_ONE_SPACE_STRING)
        return make_shared<MaxOneSpaceString>();
    else if (type == FormatTypes::PAD_LEFT_STRING)
        return make_shared<PadLeftString>();
    else if (type == FormatTypes::PAD_RIGHT_STRING)
        return make_shared<PadRightString>();
    else if (type == FormatTypes::PURE_STRING)
        return make_shared<PureString>();
    else if (type == FormatTypes::STRIPPED_STRING)
        return make_shared<StrippedString>();
    throw FormatDoesNotExistException();
}

FormatTypes FormatType::strToTypes(const std::string &input) {
    if (input == "boolean")
        return FormatTypes::BOOLEAN;
    else if (input == "date")
        return FormatTypes::DATE;
    else if (input == "float")
        return FormatTypes::FLOAT;
    else if (input == "integer")
        return FormatTypes::INTEGER;
    else if (input == "time")
        return FormatTypes::TIME;
    else if (input == "max one space string")
        return FormatTypes::MAX_ONE_SPACE_STRING;
    else if (input == "pad left string")
        return FormatTypes::PAD_LEFT_STRING;
    else if (input == "pad right string")
        return FormatTypes::PAD_RIGHT_STRING;
    else if (input == "pure string")
        return FormatTypes::PURE_STRING;
    else if (input == "stripped string")
        return FormatTypes::STRIPPED_STRING;
    throw FormatDoesNotExistException();
}
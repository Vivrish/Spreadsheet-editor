#include <algorithm>
#include "Formula.h"


Strip::Strip(): Formula() {
    signature = "strip";
}

std::string Strip::calculateStr() {
    UnaryOperator::checkStr();

    std::string formattedValue = strArgs[0];

    formattedValue.erase(formattedValue.begin(), std::find_if(formattedValue.begin(), formattedValue.end(), [](unsigned char ch) {
        return !std::isspace(ch);
    }));

    formattedValue.erase(std::find_if(formattedValue.rbegin(), formattedValue.rend(), [](unsigned char ch) {
        return !std::isspace(ch);
    }).base(), formattedValue.end());

    return formattedValue;
}
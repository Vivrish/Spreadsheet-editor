#include <algorithm>
#include "Formula.h"
#include "regex"


Strip::Strip(): Formula() {
    signature = "strip";
}

std::string Strip::calculateStr() {
    UnaryOperator::checkStr();

    std::string output = strArgs[0];
    output = std::regex_replace(output, std::regex("^ +| +$|( ) +"), "$1");
    return output;
}
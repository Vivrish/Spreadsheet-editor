#ifndef SEMESTRALWORK_STRINGPARSER_H
#define SEMESTRALWORK_STRINGPARSER_H
#include "../CellData/CellDataType.h"
#include "../Operators/Operator.h"
#include <stack>
#include <queue>
#include <string>

class StringParser {

    bool parse(const std::string & input);

    bool scoopCellReferences(const std::string & input);

    [[nodiscard]] std::stack<CellDataType> getTokens() const;

    [[nodiscard]] std::queue<CellDataType> getOutput() const;

private:
    std::stack<Operator> tokens;
    std::queue<CellDataType> output;
};
#endif //SEMESTRALWORK_STRINGPARSER_H

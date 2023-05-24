#ifndef SEMESTRALWORK_STRINGPARSER_H
#define SEMESTRALWORK_STRINGPARSER_H
#include "../Operators/Operator.h"
#include <stack>
#include <queue>
#include <string>
#include <unordered_map>

class CellDataType;

class StringParser {

    void parseAsNumeric(const std::string & input);

    void parseAsString(const std::string & input);

    std::unordered_map<std::string, std::string> scoopCellReferences(const std::string & input);

    [[nodiscard]] std::stack<CellDataType> getTokens() const;

    [[nodiscard]] std::queue<CellDataType> getOutput() const;

    [[nodiscard]] std::string getResult() const;

private:
    std::stack<Operator> tokens;
    std::queue<CellDataType> output;
};
#endif //SEMESTRALWORK_STRINGPARSER_H

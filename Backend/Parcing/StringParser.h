#ifndef SEMESTRALWORK_STRINGPARSER_H
#define SEMESTRALWORK_STRINGPARSER_H

#include "../PairHash.h"
#include <stack>
#include <queue>
#include <string>
#include <unordered_set>


class StringParser {

public:

    StringParser() = default;

    explicit StringParser(const std::string & value);

    void parseAsNumeric(const std::string & input);

    void parseAsString(const std::string & input);

    std::unordered_set<std::pair<int, int>, PairHash> scoopCellReferences(const std::string & input);

    std::pair<int, int> getNext();

    void replaceReferenceWithValue(std::string & value);

    [[nodiscard]] std::stack<CellDataType> getTokens() const;

    [[nodiscard]] std::queue<CellDataType> getOutput() const;

    [[nodiscard]] std::string getResult() const;

private:
    std::stack<Operator> tokens;
    std::queue<CellDataType> output;
    std::string value;
};
#endif //SEMESTRALWORK_STRINGPARSER_H

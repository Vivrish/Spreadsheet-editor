#ifndef SEMESTRALWORK_STRINGPARSER_H
#define SEMESTRALWORK_STRINGPARSER_H

#include <stack>
#include <queue>
#include <string>
#include <unordered_set>
#include <memory>
#include <vector>

#include "../Operators/Operator.h"
#include "AbstractSyntaxTree.h"

struct PairHash {
    std::size_t operator () (const std::pair<int, int> & pair) const;
};

template<typename Type>
void clearStack(std::stack<Type> & input);

template<typename Type>
void clearQueue(std::queue<Type> & input);

template<typename Type>
Type getSecondFromTop(std::stack<Type> & input);

std::string queueToString(std::queue<std::string> & input);

std::string removePlainText(const std::string & input);

std::pair<int, int> parsePair(const std::string & input);

std::vector<std::string> split(const std::string & input, char delimiter, char quotation);

std::string trimSpaces(const std::string & input);

bool isNumber(const std::string & input);

bool isString(const std::string & token);

bool isOperand(const std::string & token);

bool isOperator(const std::string & input);

bool isFunction(const std::string & input);

bool insideQuotations(const std::string & input, int index);

std::pair<int, int> strToPair(const std::string & input);

std::unordered_set<std::pair<int, int>, PairHash> scoopCellReferences(const std::string &input);

void replaceReferencesWithValues(std::string & target, std::queue<std::string> & values);

std::queue<std::pair<int, int>> getOrderedReferences(const std::string &input);


class StringParser {

public:

    StringParser() = default;

    void parse(const std::string & input);

    [[nodiscard]] std::queue<std::string> getOutput() const;

    [[nodiscard]] std::shared_ptr<ASTNode> getAST() const;

private:
    std::stack<std::shared_ptr<Operator>> operators;
    std::queue<std::string> output;
    std::stack<std::shared_ptr<ASTNode>> outputNodes;
};
#endif //SEMESTRALWORK_STRINGPARSER_H

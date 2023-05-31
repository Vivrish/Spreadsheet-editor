#include "StringParser.h"
#include <regex>
#include "../Operators/Operator.h"
#include "../Formulas/Formula.h"
#include "../Exceptions/Exceptions.h"


using namespace std;


size_t PairHash::operator()(const pair<int, int> &pair) const {
    return hash<int>()(pair.first) xor hash<int>()(pair.second);
}

template<typename Type>
void clearQueue(std::queue<Type> &input) {
    queue<Type>().swap(input);
}

template<typename Type>
void clearStack(std::stack<Type> &input) {
    while (not input.empty())
        input.pop();
}

unordered_map<string, shared_ptr<Operator>> signatureToPtr = {
        {"+",     make_shared<Plus>()},
        {"-",     make_shared<Minus>()},
        {"*",     make_shared<Multiply>()},
        {"/",     make_shared<Divide>()},
        {"^",     make_shared<Power>()},
        {"sin",   make_shared<Sin>()},
        {"cos",   make_shared<Cos>()},
        {"strip", make_shared<Strip>()},
        {")",     make_shared<RightParentheses>()},
        {"(",     make_shared<LeftParentheses>()}
};

const unordered_set<string> functions = {"sin", "cos", "strip"};

const unordered_set<string> operatorSignatures = {"+", "-", "*", "/", "^"};


std::unordered_set<std::pair<int, int>, PairHash> scoopCellReferences(const std::string &input) {
    regex pattern("(\\d+:\\d+)");
    unordered_set<pair<int, int>, PairHash> out;
    string inputWithoutQuotedText = removePlainText(input);

    sregex_iterator iterMatch(inputWithoutQuotedText.begin(), inputWithoutQuotedText.end(), pattern);
    sregex_iterator end;

    while (iterMatch != end) {
        out.insert(parsePair(iterMatch->str()));
        iterMatch++;
    }

    return out;
}

std::pair<int, int> parsePair(const std::string &input) {
    regex pattern("(\\d+:\\d+)");
    smatch matches;

    if (regex_match(input, matches, pattern)) {
        int first = stoi(matches[0]);
        int second = stoi(matches[1]);
        return {first, second};
    }

    return {-1, -1};
}

std::string removePlainText(const std::string &input) {
    string output;
    bool quotedZone = false;

    for (char symbol: input) {
        if (symbol == '\"')
            quotedZone = not quotedZone;
        else {
            if (not quotedZone)
                output.push_back(symbol);
        }
    }

    return output;
}

std::vector<std::string> split(const std::string &input, char delimiter) {
    vector<string> output;
    istringstream stream(input);
    string element;

    while (getline(stream, element, delimiter)) {
        output.push_back(element);
    }

    return output;
}

std::string trimSpaces(const std::string &input) {
    bool prevSpace = false;
    string output;
    for (char letter: input) {
        if (isspace(letter)) {
            if (not prevSpace)
                output.push_back(letter);
            prevSpace = true;
        } else {
            output.push_back(letter);
            prevSpace = false;
        }
    }
    return output;
}

bool isNumber(const std::string &input) {
    return all_of(input.begin(), input.end(), [](char c) { return isdigit(c); });
}

bool isString(const std::string & input) {
    if (input.size() < 2)
        return false;
    if (input.front() != '\"' or input.back() != '\"')
        return false;
    if (std::count(input.begin(), input.end(), '\"') != 2)
        return false;
    return true;
}



bool isOperand(const string &token) {
    return isString(token) or isNumber(token);
}

bool isOperator(const string &input) {
    return operatorSignatures.count(input) != 0;
}

bool isFunction(const string &input) {
    return functions.count(input) != 0;
}

void StringParser::parse(const std::string &input) {
    clearStack(operators);
    clearQueue(output);

    string tokens = trimSpaces(input);

    vector<string> splitTokens = split(tokens, ' ');

    shared_ptr<Operator> operatorToken;
    for (const string &token: splitTokens) {
        if (isOperand(token))
            output.push(token);
        else if (isFunction(token))
            operators.push(signatureToPtr[token]);
        else if (isOperator(token)) {
            operatorToken = signatureToPtr[token];
            if (not operators.empty()) {

                while (
                        operators.top()->getSignature() != "(" and
                       (operators.top()->getPrecedence() > operatorToken->getPrecedence()
                        or (operators.top()->getPrecedence() ==
                            operatorToken->getPrecedence() and
                            operatorToken->getAssociativity() ==
                            Associativity::LEFT))) {
                    output.push(operators.top()->getSignature());
                    operators.pop();
                    if (operators.empty())
                        break;
                }
            }

            operators.push(operatorToken);
        }
        else if (token == "(")
            operators.push(signatureToPtr["("]);
        else if (token == ")") {
            while (operators.top()->getSignature() != "(") {
                if (operators.empty())
                    throw MismatchedParenthesisException();
                output.push(operators.top()->getSignature());
                operators.pop();
                if (operators.empty())
                    break;
            }
            if (operators.empty() or operators.top()->getSignature() != "(")
                throw MismatchedParenthesisException();
            operators.pop();
            if (not operators.empty() and isFunction(operators.top()->getSignature())) {
                output.push(operators.top()->getSignature());
                operators.pop();
            }
        }

    }

    while (not operators.empty()) {
        if (operators.top()->getSignature() == "(")
            throw MismatchedParenthesisException();
        output.push(operators.top()->getSignature());
        operators.pop();
    }


}


std::queue<std::string> StringParser::getOutput() const {
    return output;
}
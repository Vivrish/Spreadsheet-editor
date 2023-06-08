#include "StringParser.h"
#include <regex>
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

template<typename Type>
Type getSecondFromTop(std::stack<Type> &input) {
    Type tmp = input.top();
    input.pop();
    Type output = input.top();
    input.push(tmp);
    return output;
}

std::string queueToString(std::queue<std::string> & input) {
    std::ostringstream oss;
    while (!input.empty()) {
        oss << input.front();
        input.pop();
        if (!input.empty()) {
            oss << ' ';
        }
    }
    return oss.str();
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


shared_ptr<BinaryOperator> binaryOperatorGenerator(const string &input) {
    if (input == "+")
        return make_shared<Plus>();
    else if (input == "-")
        return make_shared<Minus>();
    else if (input == "*")
        return make_shared<Multiply>();
    else if (input == "/")
        return make_shared<Divide>();
    else if (input == "^")
        return make_shared<Power>();

    throw InvalidOperationException();
}


shared_ptr<UnaryOperator> unaryOperatorGenerator(const string &input) {
    if (input == "sin")
        return make_shared<Sin>();
    else if (input == "cos")
        return make_shared<Cos>();
    else if (input == "strip")
        return make_shared<Strip>();

    throw InvalidOperationException();
}

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

queue<pair<int, int>> getOrderedReferences(const string &input) {
    regex pattern("(\\d+:\\d+)");
    queue<pair<int, int>> out;
    string inputWithoutQuotedText = removePlainText(input);

    sregex_iterator iterMatch(inputWithoutQuotedText.begin(), inputWithoutQuotedText.end(), pattern);
    sregex_iterator end;

    while (iterMatch != end) {
        out.push(parsePair(iterMatch->str()));
        iterMatch++;
    }

    return out;
}

std::pair<int, int> parsePair(const std::string &input) {
    string delim = ":";
    size_t pos = input.find(delim);

    if (pos != string::npos) {
        return {stoi(input.substr(0, pos)), stoi(input.substr(pos + delim.length()))};
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

std::vector<std::string> split(const std::string &input, char delimiter, char quotation) {
    vector<string> output;
    string element;

    bool inQuotes = false;

    for (char symbol: input) {
        if (symbol == quotation)
            inQuotes = not inQuotes;
        if (symbol == delimiter and not inQuotes) {
            if (not element.empty())
                output.push_back(element);
            element.clear();
        } else element += symbol;
    }

    if (not element.empty())
        output.push_back(element);

    return output;
}

std::string trimSpaces(const std::string &input) {
    bool prevSpace = false;
    bool inQuotes = false;
    string output;
    for (char letter: input) {
        if (letter == '\"')
            inQuotes = not inQuotes;
        if (inQuotes) {
            output.push_back(letter);
            prevSpace = false;
        }
        else {
            if (isspace(letter)) {
                if (not prevSpace)
                    output.push_back(letter);
                prevSpace = true;
            } else {
                output.push_back(letter);
                prevSpace = false;
            }
        }
    }
    return output;
}

bool isNumber(const std::string &input) {
    int dotCount = 0, minusCount = 0;
    if (input == "-")
        return false;
    for (size_t i = 0; i < input.size(); i++) {
        if (input[i] == '.')
            dotCount++;
        if (input[i] == '-')
            minusCount++;
        if (i == 0) {
            if (input[i] != '-' and input[i] != '.' and not isdigit(input[i]))
                return false;
        } else if (not isdigit(input[i]) and input[i] != '.')
            return false;
    }
    if (minusCount > 1 or dotCount > 1)
        return false;
    return true;
}

bool isString(const std::string &input) {
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

bool insideQuotations(const string & input, int index) {
    if (index >= (int) input.size())
        throw IndexOutOfBoundsException();

    bool inQuotes = false;

    for (int i = 0; i <= index; i++) {
        if (input[i] == '\"')
            inQuotes = not inQuotes;
    }
    return inQuotes;
}

pair<int, int> strToPair(const string & input) {
    string delim = ":";
    size_t pos = input.find(delim);

    if (pos != string::npos) {
        string first = input.substr(0, pos);
        string second = input.substr(pos + delim.length());
        return {stoi(first), stoi(second)};
    }

    return {-1, -1};
}

void handleOperator(stack<shared_ptr<ASTNode>> &nodes, const string &op) {
    if (isOperator(op)) {
        if (nodes.size() < 2)
            throw BadSyntaxException();
        shared_ptr<ASTNode> newNode = make_shared<BinaryOperatorNode>(binaryOperatorGenerator(op), nodes.top(),
                                                                      getSecondFromTop(nodes));
        nodes.pop();
        nodes.pop();
        nodes.push(newNode);
    } else if (isFunction(op)) {
        if (nodes.empty())
            throw BadSyntaxException();
        shared_ptr<ASTNode> newNode = make_shared<UnaryOperatorNode>(unaryOperatorGenerator(op), nodes.top());
        nodes.pop();
        nodes.push(newNode);
    } else throw InvalidOperationException();
}

void StringParser::parse(const std::string &input) {
    clearStack(operators);
    clearQueue(output);
    clearStack(outputNodes);

    string tokens = trimSpaces(input);

    vector<string> splitTokens = split(tokens, ' ', '\"');

    shared_ptr<Operator> operatorToken;
    for (const string &token: splitTokens) {
        if (isOperand(token)) {
            outputNodes.push(make_shared<ValueNode>(token));
            output.push(token);
        } else if (isFunction(token))
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
                    handleOperator(outputNodes, operators.top()->getSignature());
                    operators.pop();
                    if (operators.empty())
                        break;
                }
            }

            operators.push(operatorToken);
        } else if (token == "(")
            operators.push(signatureToPtr["("]);
        else if (token == ")") {
            while (operators.top()->getSignature() != "(") {
                if (operators.empty())
                    throw MismatchedParenthesisException();
                output.push(operators.top()->getSignature());
                handleOperator(outputNodes, operators.top()->getSignature());
                operators.pop();
                if (operators.empty())
                    break;
            }
            if (operators.empty() or operators.top()->getSignature() != "(")
                throw MismatchedParenthesisException();
            operators.pop();
            if (not operators.empty() and isFunction(operators.top()->getSignature())) {
                output.push(operators.top()->getSignature());
                handleOperator(outputNodes, operators.top()->getSignature());
                operators.pop();
            }
        }

    }

    while (not operators.empty()) {
        if (operators.top()->getSignature() == "(")
            throw MismatchedParenthesisException();
        output.push(operators.top()->getSignature());
        handleOperator(outputNodes, operators.top()->getSignature());
        operators.pop();
    }


}


std::queue<std::string> StringParser::getOutput() const {
    return output;
}

std::shared_ptr<ASTNode> StringParser::getAST() const {
    if (outputNodes.empty())
        return make_shared<ValueNode>("");
    return outputNodes.top();
}


void replaceReferencesWithValues(std::string & target, std::queue<std::string> & values) {
    regex pattern("^\\d+:\\d+$");
    vector<string> splitTarget = split(target,' ', '\"');
    string output;
    bool first = true;
    for (const string & el: splitTarget) {
        if (not first) {
            output += " ";
        }
        first = false;
        if (regex_match(el, pattern)) {
            if (values.empty())
                throw ReferenceMismatchException();
            output += values.front();
            values.pop();
        }
        else {
            output += el;
        }
    }

    if (not values.empty())
        throw ReferenceMismatchException();

    target = output;
}


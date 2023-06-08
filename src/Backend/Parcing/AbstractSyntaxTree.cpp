#include "AbstractSyntaxTree.h"
#include "../Exceptions/Exceptions.h"

using namespace std;





ostream & operator << (ostream & os, const ASTNode & node) {
    node.print(os);
    return os;
}

BinaryOperatorNode::BinaryOperatorNode(std::shared_ptr<BinaryOperator> pOp, std::shared_ptr<ASTNode> pLeft,
                                       std::shared_ptr<ASTNode> pRight) {
    op = pOp;
    left = pLeft;
    right = pRight;
}

void BinaryOperatorNode::addNode(std::shared_ptr<ASTNode> & input) {
    if (left != nullptr) {
        if (right != nullptr)
            throw IncorrectAmountOfArgumentsException();
        right = input;
    } else left = input;
}

void BinaryOperatorNode::addValue(const std::string &input) {
    throw InvalidArgumentException();
}

double BinaryOperatorNode::getNumericResult() {
    op->addArgument(left->getNumericResult());
    op->addArgument(right->getNumericResult());
    return op->calculateNum();
}

std::string BinaryOperatorNode::getStringResult() {
    op->addArgument(left->getStringResult());
    op->addArgument(right->getStringResult());
    return op->calculateStr();
}

void BinaryOperatorNode::print(std::ostream &os) const {
    os << "BOP node " << op->getSignature() << endl;
    left->print(os);
    right->print(os);
}

UnaryOperatorNode::UnaryOperatorNode(std::shared_ptr<UnaryOperator> pOp, std::shared_ptr<ASTNode> pArgument) {
    op = pOp;
    argument = pArgument;
}

void UnaryOperatorNode::addValue(const std::string &input) {
    throw InvalidArgumentException();
}

void UnaryOperatorNode::addNode(std::shared_ptr<ASTNode> &input) {
    if (argument == nullptr)
        throw IncorrectAmountOfArgumentsException();
    argument = input;
}

double UnaryOperatorNode::getNumericResult() {
    op->addArgument(argument->getNumericResult());
    return op->calculateNum();
}

std::string UnaryOperatorNode::getStringResult() {
    op->addArgument(argument->getStringResult());
    return op->calculateStr();
}

void UnaryOperatorNode::print(std::ostream &os) const {
    os << "UOP node " << op->getSignature() << endl;
    argument->print(os);
}

ValueNode::ValueNode(const std::string &pValue) {
    value = pValue;
}

void ValueNode::addNode(std::shared_ptr<ASTNode> &input) {
    throw InvalidArgumentException();
}

void ValueNode::addValue(const std::string &input) {
    value = input;
}

std::string ValueNode::getStringResult() {
    return value;
}

double ValueNode::getNumericResult() {
    return stod(value);
}

void ValueNode::print(std::ostream &os) const {
    os << "Value node " << value << endl;
}
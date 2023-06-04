#ifndef ISOLATION_ABSTRACTSYNTAXTREE_H
#define ISOLATION_ABSTRACTSYNTAXTREE_H
// todo ifndef

#include "../Operators/Operator.h"
#include <memory>
#include <iostream>


class ASTNode {
public:

    virtual void addValue(const std::string & input) = 0;
    virtual void addNode(std::shared_ptr<ASTNode> & input) = 0;
    virtual std::string getStringResult() = 0;
    virtual double getNumericResult() = 0;
    virtual void print(std::ostream & os) const = 0;

    friend std::ostream & operator << (std::ostream & os, const ASTNode & node);

};

class BinaryOperatorNode: public ASTNode {
public:

    BinaryOperatorNode(std::shared_ptr<BinaryOperator> pOp, std::shared_ptr<ASTNode> pLeft, std::shared_ptr<ASTNode> pRight);

    void addNode(std::shared_ptr<ASTNode> & input) override;
    void addValue(const std::string &input) override;
    double getNumericResult() override;
    std::string getStringResult() override;
    void print(std::ostream &os) const override;

private:
    std::shared_ptr<BinaryOperator> op;
    std::shared_ptr<ASTNode> left;
    std::shared_ptr<ASTNode> right;
};

class UnaryOperatorNode: public ASTNode {
public:

    UnaryOperatorNode(std::shared_ptr<UnaryOperator> pOp, std::shared_ptr<ASTNode> pArgument);

    void addNode(std::shared_ptr<ASTNode> & input) override;
    void addValue(const std::string &input) override;
    double getNumericResult() override;
    std::string getStringResult() override;
    void print(std::ostream &os) const override;

private:
    std::shared_ptr<UnaryOperator> op;
    std::shared_ptr<ASTNode> argument;
};

class ValueNode: public ASTNode {
public:
    explicit ValueNode(const std::string & pValue);

    void addNode(std::shared_ptr<ASTNode> & input) override;
    void addValue(const std::string &input) override;
    double getNumericResult() override;
    std::string getStringResult() override;
    void print(std::ostream &os) const override;

private:
    std::string value;
};




#endif //ISOLATION_ABSTRACTSYNTAXTREE_H

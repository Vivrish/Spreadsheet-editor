#ifndef SEMESTRALWORK_OPERATOR_H
#define SEMESTRALWORK_OPERATOR_H
#include <string>
#include <vector>
#include <iostream>

enum class Associativity {
    RIGHT, LEFT
};



class Operator {
public:
    virtual void addArgument(double argument);
    virtual void addArgument(const std::string & argument);
    virtual void clear();
    [[nodiscard]] virtual std::string getSignature() const;
    [[nodiscard]] virtual int getPrecedence() const;
    [[nodiscard]] virtual Associativity getAssociativity() const;

    virtual std::string calculateStr();
    virtual double calculateNum();
    virtual void checkNum() = 0;
    virtual void checkStr() = 0;
    virtual ~Operator() = default;

protected:
    std::string signature;
    Associativity associativity;
    int precedence;
    std::vector<double> numArgs;
    std::vector<std::string> strArgs;
};

class LeftParentheses: public Operator {
public:
    LeftParentheses();
    void checkStr() override {};
    void checkNum() override {};

};

class RightParentheses: public Operator {
public:
    RightParentheses();
    void checkStr() override {};
    void checkNum() override {};

};

class BinaryOperator: public Operator {
public:

    void checkNum() override;
    void checkStr() override;
};

class Plus: public BinaryOperator {
public:
    Plus();
    std::string calculateStr() override;
    double calculateNum() override;
};

class Minus: public BinaryOperator {
public:
    Minus();
    std::string calculateStr() override;
    double calculateNum() override;

};

class Multiply: public BinaryOperator {
public:
    Multiply();
    std::string calculateStr() override;
    double calculateNum() override;
private:
    std::string calculateStrNum();
};

class Divide: public BinaryOperator {
public:
    Divide();
    double calculateNum() override;
    std::string calculateStr() override;
};

class Power: public BinaryOperator {
public:
    Power();
    double calculateNum() override;

};

class UnaryOperator: public Operator {
public:
    void checkNum() override;
    void checkStr() override;
};


#endif //SEMESTRALWORK_OPERATOR_H

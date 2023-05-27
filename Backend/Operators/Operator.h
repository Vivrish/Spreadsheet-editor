#ifndef SEMESTRALWORK_OPERATOR_H
#define SEMESTRALWORK_OPERATOR_H
#include <string>
#include <vector>

enum class Associativity {
    RIGHT, LEFT
};

class Operator {
public:
    void addArgument(double argument);
    void addArgument(const std::string & argument);

    virtual std::string calculateStr();
    virtual double calculateNum();
    virtual void checkNum() = 0;
    virtual void checkStr() = 0;
    void clear();
    virtual ~Operator() = default;

protected:
    std::string signature;
    Associativity associativity;
    int precedence;
    std::vector<double> numArgs;
    std::vector<std::string> strArgs;
};

class BinaryOperator: public Operator {
public:
    std::string calculateStr() override = 0;
    double calculateNum() override = 0;

    void checkNum() override;
    void checkStr() override;
};

class Plus: public BinaryOperator {
public:
    std::string calculateStr() override;
    double calculateNum() override;
protected:
    std::string signature  = "+";
    Associativity associativity = Associativity::LEFT;
    int precedence = 2;
};

class Minus: public BinaryOperator {
public:
    std::string calculateStr() override;
    double calculateNum() override;
protected:
    std::string signature  = "-";
    Associativity associativity = Associativity::LEFT;
    int precedence = 2;
};

class Multiply: public BinaryOperator {
public:
    std::string calculateStr() override;
    double calculateNum() override;
protected:
    Associativity associativity = Associativity::LEFT;
    int precedence = 3;
    std::string signature  = "*";
private:
    std::string calculateStrNum();
};

class Divide: public BinaryOperator {
public:
    double calculateNum() override;
    std::string calculateStr() override;
protected:
    Associativity associativity = Associativity::LEFT;
    int precedence = 3;
    std::string signature  = "/";
};

class Power: public BinaryOperator {
public:
    double calculateNum() override;
protected:
    std::string signature  = "^";
    Associativity associativity = Associativity::RIGHT;
    int precedence = 4;
};

class UnaryOperator: public Operator {
public:
    std::string calculateStr() override = 0;
    double calculateNum() override = 0;
    void checkNum() override;
    void checkStr() override;
};


#endif //SEMESTRALWORK_OPERATOR_H

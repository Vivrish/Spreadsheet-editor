#ifndef SEMESTRALWORK_OPERATOR_H
#define SEMESTRALWORK_OPERATOR_H
#include "../CellData/CellDataType.h"
#include <string>
#include <vector>
class Operator {
public:
    bool addArgument(double argument);
    bool addArgument(const std::string & argument);

    virtual String calculateStr() = 0;
    virtual Numeric calculateNum() = 0;

protected:
    std::string signature;
    std::vector<double> numArgs;
    std::vector<std::string> strArgs;
};

class BinaryOperator: public Operator {
public:
    String calculateStr() override = 0;
    Numeric calculateNum() override = 0;
};

class Plus: public BinaryOperator {
public:
    String calculateStr() override;
    Numeric calculateNum() override;
};

class Multiply: public BinaryOperator {
public:
    String calculateStr() override;
    Numeric calculateNum() override;
};

class Divide: public BinaryOperator {
public:
    String calculateStr() override;
    Numeric calculateNum() override;
};

class UnaryOperator: public Operator {
    String calculateStr() override = 0;
    Numeric calculateNum() override = 0;
};


#endif //SEMESTRALWORK_OPERATOR_H

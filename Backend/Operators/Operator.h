#ifndef SEMESTRALWORK_OPERATOR_H
#define SEMESTRALWORK_OPERATOR_H
#include "../CellDataType.h"
class Operator {
    virtual PureString calculate(const PureString & one, const PureString & other);
    virtual Number calculate(const Number & one, const Number & other);
    virtual Boolean calculate(const Boolean & one, const Boolean & other);
    virtual Date calculate(const Date & one, const Date & other);
    virtual Time calculate(const Time & one, const Time & other);
};

class Plus: public Operator {
    PureString calculate(const PureString & one, const PureString & other) final;
    Number calculate(const Number & one, const Number & other) final;
    Boolean calculate(const Boolean & one, const Boolean & other) final;
    Date calculate(const Date & one, const Date & other) final;
    Time calculate(const Time & one, const Time & other) final;
};

class Multiply: public Operator {
    PureString calculate(const PureString & one, const PureString & other) final;
    Number calculate(const Number & one, const Number & other) final;
    Boolean calculate(const Boolean & one, const Boolean & other) final;
    Date calculate(const Date & one, const Date & other) final;
    Time calculate(const Time & one, const Time & other) final;
};

class Divide: public Operator {
    Number calculate(const Number & one, const Number & other) final;
    Date calculate(const Date & one, const Date & other) final;
};

class And: public Operator {
    PureString calculate(const PureString & one, const PureString & other) final;
    Number calculate(const Number & one, const Number & other) final;
    Boolean calculate(const Boolean & one, const Boolean & other) final;
    Date calculate(const Date & one, const Date & other) final;
    Time calculate(const Time & one, const Time & other) final;
};

class Or: public Operator {
    PureString calculate(const PureString & one, const PureString & other) final;
    Number calculate(const Number & one, const Number & other) final;
    Boolean calculate(const Boolean & one, const Boolean & other) final;
    Date calculate(const Date & one, const Date & other) final;
    Time calculate(const Time & one, const Time & other) final;
};

#endif //SEMESTRALWORK_OPERATOR_H

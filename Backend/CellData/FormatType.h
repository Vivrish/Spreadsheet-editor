#ifndef SEMESTRALWORK_FORMATTYPE_H
#define SEMESTRALWORK_FORMATTYPE_H
#include <string>
class FormatType {
public:

    FormatType(const std::string & pRawValue);

    virtual bool format() = 0;

    std::string getFormattedValue() const;

protected:
    std::string rawValue;
    std::string formattedValue;
};


class NumericFormatType: public  FormatType {
public:
    NumericFormatType(const std::string & pRawValue, double pRawNumericValue);

    bool format() override = 0;

protected:
    double rawNumericValue;
};

class Time: public  NumericFormatType {
public:
    bool format() override;
};

class Date: public NumericFormatType {
public:
    bool format() override;
};

class Boolean: public NumericFormatType {
public:
    bool format() override;
};

class Integer: public NumericFormatType {
public:
    bool format() override;
};

class Float: public NumericFormatType {
public:
    bool format() override;
};

class StringFormatType: public FormatType {
public:
    bool format() override = 0;
};

class PadLeftString: public StringFormatType {
public:
    bool format() override;
};

class PadRightString: public StringFormatType {
public:
    bool format() override;
};

class MaxOneSpaceString: public StringFormatType {
public:
    bool format() override;
};

class StrippedString: public StringFormatType {
public:
    bool format() override;
};

class PureString: public StringFormatType {
public:
    bool format() override;
};

#endif //SEMESTRALWORK_FORMATTYPE_H

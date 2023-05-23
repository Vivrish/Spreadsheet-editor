#ifndef SEMESTRALWORK_FORMATTYPE_H
#define SEMESTRALWORK_FORMATTYPE_H
#include <string>

class FormatType {
public:

    explicit FormatType(const std::string & pRawValue);

    virtual void format() = 0;

    [[nodiscard]] std::string getFormattedValue() const;

protected:
    std::string rawValue;
    std::string formattedValue;
};


class NumericFormatType: public FormatType {
public:
    explicit NumericFormatType(const std::string & pRawValue);

    void format() override = 0;

protected:
    double rawNumericValue;
};

class Time: public  NumericFormatType {
public:
    void format() override;

};

class Date: public NumericFormatType {
public:
    void format() override;
};

class Boolean: public NumericFormatType {
public:
    void format() override;
};

class Integer: public NumericFormatType {
public:
    void format() override;
};

class Float: public NumericFormatType {
public:
    void format() override;
};

class StringFormatType: public FormatType {
    explicit StringFormatType(const std::string & pRawValue);
    void format() override = 0;
};

class PadLeftString: public StringFormatType {
public:
    void format() override;
};

class PadRightString: public StringFormatType {
public:
    void format() override;
};

class MaxOneSpaceString: public StringFormatType {
public:
    void format() override;
};

class StrippedString: public StringFormatType {
public:
    void format() override;
};

class PureString: public StringFormatType {
public:
    void format() override;
};

#endif //SEMESTRALWORK_FORMATTYPE_H

#ifndef SEMESTRALWORK_FORMATTYPE_H
#define SEMESTRALWORK_FORMATTYPE_H
#include <string>
#include <memory>

class FormatType {
public:

    explicit FormatType(const std::string & pRawValue);

    void setValue(const std::string & val);

    virtual void format() = 0;

    virtual std::shared_ptr<FormatType> getCopy() = 0;

    [[nodiscard]] std::string getFormattedValue() const;

protected:
    std::string rawValue;
    std::string formattedValue;
};


class NumericFormatType: public FormatType {
public:
    explicit NumericFormatType(const std::string & pRawValue);

protected:
    double rawNumericValue;
};

class Time: public  NumericFormatType {
public:
    explicit Time(const std::string & pRawValue);
    void format() override;
    std::shared_ptr<FormatType> getCopy() override;
};

class Date: public NumericFormatType {
public:
    explicit Date(const std::string & pRawValue);
    void format() override;
    std::shared_ptr<FormatType> getCopy() override;


};

class Boolean: public NumericFormatType {
public:
    explicit Boolean(const std::string & pRawValue);
    void format() override;
    std::shared_ptr<FormatType> getCopy() override;
};

class Integer: public NumericFormatType {
public:
    explicit Integer(const std::string & pRawValue);
    void format() override;
    std::shared_ptr<FormatType> getCopy() override;
};

class Float: public NumericFormatType {
public:
    explicit Float(const std::string & pRawValue);
    void format() override;
    std::shared_ptr<FormatType> getCopy() override;
};

class StringFormatType: public FormatType {
public:
    explicit StringFormatType(const std::string & pRawValue);
};

class PadLeftString: public StringFormatType {
public:
    explicit PadLeftString(const std::string & pRawValue);
    void format() override;
    std::shared_ptr<FormatType> getCopy() override;
};

class PadRightString: public StringFormatType {
public:
    explicit PadRightString(const std::string & pRawValue);
    void format() override;
    std::shared_ptr<FormatType> getCopy() override;
};

class MaxOneSpaceString: public StringFormatType {
public:
    explicit MaxOneSpaceString(const std::string & pRawValue);
    void format() override;
    std::shared_ptr<FormatType> getCopy() override;
};

class StrippedString: public StringFormatType {
public:
    explicit StrippedString(const std::string & pRawValue);
    void format() override;
    std::shared_ptr<FormatType> getCopy() override;
};

class PureString: public StringFormatType {
public:
    explicit PureString(const std::string & pRawValue);
    void format() override;
    std::shared_ptr<FormatType> getCopy() override;
};

#endif //SEMESTRALWORK_FORMATTYPE_H

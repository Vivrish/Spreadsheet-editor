#ifndef SEMESTRALWORK_FORMATTYPE_H
#define SEMESTRALWORK_FORMATTYPE_H
#include <string>
#include <memory>
#include <unordered_map>

enum class FormatTypes {
    TIME, DATE, BOOLEAN, FLOAT, INTEGER,
    MAX_ONE_SPACE_STRING, PAD_LEFT_STRING, PAD_RIGHT_STRING, PURE_STRING, STRIPPED_STRING,
    UNKNOWN
};

class FormatType {
public:

    std::unordered_map<std::string, std::string> constants;

    FormatType();

    explicit FormatType(const std::string & pRawValue);

    virtual void setValue(const std::string & val) = 0;

    virtual void format() = 0;

    virtual std::shared_ptr<FormatType> getCopy() = 0;

    [[nodiscard]] std::string getFormattedValue() const;

    static std::shared_ptr<FormatType> generateType(const FormatTypes & type);

    static FormatTypes strToTypes(const std::string & input);

protected:
    std::string rawValue;
    std::string formattedValue;
};


class NumericFormatType: public FormatType {
public:
    NumericFormatType() = default;

    explicit NumericFormatType(const std::string & pRawValue);

    void setValue(const std::string &val) override;

protected:
    double rawNumericValue = 0;
};

class Time: public NumericFormatType {
public:
    Time() = default;
    explicit Time(const std::string & pRawValue);
    void format() override;
    std::shared_ptr<FormatType> getCopy() override;
};

class Date: public NumericFormatType {
public:
    Date() = default;
    explicit Date(const std::string & pRawValue);
    void format() override;
    std::shared_ptr<FormatType> getCopy() override;


};

class Boolean: public NumericFormatType {
public:
    Boolean() = default;
    explicit Boolean(const std::string & pRawValue);
    void format() override;
    std::shared_ptr<FormatType> getCopy() override;
};

class Integer: public NumericFormatType {
public:
    Integer() = default;
    explicit Integer(const std::string & pRawValue);
    void format() override;
    std::shared_ptr<FormatType> getCopy() override;
};

class Float: public NumericFormatType {
public:
    Float() = default;
    explicit Float(const std::string & pRawValue);
    void format() override;
    std::shared_ptr<FormatType> getCopy() override;
};

class StringFormatType: public FormatType {
public:
    StringFormatType() = default;
    explicit StringFormatType(const std::string & pRawValue);
    void setValue(const std::string &val) override;
};

class PadLeftString: public StringFormatType {
public:
    PadLeftString() = default;
    explicit PadLeftString(const std::string & pRawValue);
    void format() override;
    std::shared_ptr<FormatType> getCopy() override;
};

class PadRightString: public StringFormatType {
public:
    PadRightString() = default;
    explicit PadRightString(const std::string & pRawValue);
    void format() override;
    std::shared_ptr<FormatType> getCopy() override;
};

class MaxOneSpaceString: public StringFormatType {
public:
    MaxOneSpaceString() = default;
    explicit MaxOneSpaceString(const std::string & pRawValue);
    void format() override;
    std::shared_ptr<FormatType> getCopy() override;
};

class StrippedString: public StringFormatType {
public:
    StrippedString() = default;
    explicit StrippedString(const std::string & pRawValue);
    void format() override;
    std::shared_ptr<FormatType> getCopy() override;
};

class PureString: public StringFormatType {
public:
    PureString() = default;
    explicit PureString(const std::string & pRawValue);
    void format() override;
    std::shared_ptr<FormatType> getCopy() override;
};

#endif //SEMESTRALWORK_FORMATTYPE_H

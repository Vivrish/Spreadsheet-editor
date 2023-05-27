#ifndef SEMESTRALWORK_CELLDATATYPE_H
#define SEMESTRALWORK_CELLDATATYPE_H
#include <string>
#include <memory>
#include "../Parcing/StringParser.h"


class CellDataType {
public:

    explicit CellDataType(const std::string & pValue);

    [[nodiscard]] std::string getRawValue() const;

    virtual void evaluate() = 0;

    virtual std::shared_ptr<CellDataType> getCopy() = 0;

    [[nodiscard]] std::string getResult() const;

    void setRawValue(const std::string & val);

    virtual ~CellDataType() = default;

protected:
    std::string rawValue;
    std::string result;
    StringParser stringParser = StringParser();
};

class String: public CellDataType {

public:

    explicit String(const std::string & pValue);

    void evaluate() override;

    std::shared_ptr<CellDataType> getCopy() override;
};


class Numeric: public CellDataType {

public:

    explicit Numeric(const std::string & pValue);

    void evaluate() override;

    std::shared_ptr<CellDataType> getCopy() override;
};


#endif //SEMESTRALWORK_CELLDATATYPE_H

#ifndef SEMESTRALWORK_CELLDATATYPE_H
#define SEMESTRALWORK_CELLDATATYPE_H
#include <string>
#include <memory>
#include "../Parcing/StringParser.h"

enum class CellDataTypes {
    NUMERIC, STRING,
    UNKNOWN
};



class CellDataType {
public:

    CellDataType() = default;

    explicit CellDataType(const std::string & pValue);

    [[nodiscard]] virtual std::string getRawValue() const;

    virtual void evaluate() = 0;

    virtual std::shared_ptr<CellDataType> getCopy() = 0;

    [[nodiscard]] virtual std::string getResult() const;

    virtual void setRawValue(const std::string & val);

    virtual void setEvaluatedReferences(const std::string & val);

    virtual ~CellDataType() = default;

    static std::shared_ptr<CellDataType> generateType(CellDataTypes type);

    static CellDataTypes strToTypes(const std::string & input);

protected:
    std::string rawValue;
    std::string evaluatedRefsValue;
    std::string result;
    StringParser stringParser = StringParser();
};

class String: public CellDataType {

public:
    String() = default;

    explicit String(const std::string & pValue);

    void evaluate() override;

    std::shared_ptr<CellDataType> getCopy() override;
};


class Numeric: public CellDataType {

public:

    Numeric() = default;

    explicit Numeric(const std::string & pValue);

    void evaluate() override;

    std::shared_ptr<CellDataType> getCopy() override;
};


#endif //SEMESTRALWORK_CELLDATATYPE_H

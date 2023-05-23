#ifndef SEMESTRALWORK_CELLDATATYPE_H
#define SEMESTRALWORK_CELLDATATYPE_H
#include <string>
//#include "../Parcing/StringParser.h"
//todo
// Solve include loop
class CellDataType {
public:

    explicit CellDataType(const std::string & pValue);

    [[nodiscard]] std::string getRawValue() const;

    virtual void evaluate() = 0;

    [[nodiscard]] std::string getResult() const;

protected:
    std::string rawValue;
    std::string result;
    StringParser stringParser = StringParser();
};

class String: public CellDataType {

    explicit String(const std::string & pValue);

    void evaluate() override;


};


class Numeric: public CellDataType {

    explicit Numeric(const std::string & pValue);

    void evaluate() override;


};


#endif //SEMESTRALWORK_CELLDATATYPE_H

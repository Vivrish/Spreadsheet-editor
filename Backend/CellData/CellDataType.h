#ifndef SEMESTRALWORK_CELLDATATYPE_H
#define SEMESTRALWORK_CELLDATATYPE_H
#include <string>
class CellDataType {
public:

    [[nodiscard]] std::string getRawValue() const;

protected:
    std::string rawValue;
};

class String: public CellDataType {
    String(std::string pValue);


private:
    std::string value;
};


class Numeric: public CellDataType {
    Numeric(double pValue);

private:
    double value;
};


#endif //SEMESTRALWORK_CELLDATATYPE_H

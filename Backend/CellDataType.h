#ifndef SEMESTRALWORK_CELLDATATYPE_H
#define SEMESTRALWORK_CELLDATATYPE_H
#include <string>
class CellDataType {
public:
    virtual CellDataType * getValue() = 0;

    [[nodiscard]] std::string getRawValue() const;

    void clear();

protected:
    std::string rawValue;
};

class PureString: public CellDataType {
    PureString(std::string pValue);
    CellDataType * getValue() final;

private:
    std::string value;
};


class Number: public CellDataType {
    Number(double pValue);
    CellDataType * getValue() final;
private:
    double value;

};

class Boolean: public CellDataType {
    Boolean(bool pValue);
    CellDataType * getValue() final;
private:
    bool value;
};

class Time: public CellDataType {
public:
    Time(int pSeconds, int pMinutes, int pHours);
    CellDataType * getValue() final;
    void setActualTime();
private:
    int seconds, minutes, hours;
};

class Date: public CellDataType {
public:
    Date(int pDay, int pMonth, int pYear);
    CellDataType * getValue() final;
    void setActualDate();
private:
    int day, month, year;
};


class CellReference: public CellDataType {
public:
    CellReference(const std::pair<int, int> & pPosition);
    CellReference(const std::string & letter, int number);
    CellDataType * getValue() final;
private:
    std::pair<int, int> position;
};
#endif //SEMESTRALWORK_CELLDATATYPE_H

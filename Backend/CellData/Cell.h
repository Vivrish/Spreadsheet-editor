#ifndef SEMESTRALWORK_CELL_H
#define SEMESTRALWORK_CELL_H
#include "CellDataType.h"
#include "StoredData.h"
#include "FormatType.h"

class Cell {
    Cell(int row, int column, const CellDataType & pValue);
    Cell(const Cell & source);

    bool evaluateExpression();

    bool formatExpression();

    void setType();

    void setFormat();

    std::string getOutput() const;

private:
    std::pair<int, int> position;
    CellDataType * value;
    FormatType * formatType;
    StoredData type;
    std::string output;
};

#endif //SEMESTRALWORK_CELL_H

#ifndef SEMESTRALWORK_CELL_H
#define SEMESTRALWORK_CELL_H
#include "CellDataType.h"
#include "StoredData.h"

class Cell {
    Cell(int row, int column, const CellDataType & pValue);
    Cell(const Cell & source);


private:
    std::pair<int, int> position;
    CellDataType * value;
    StoredData type;
};

#endif //SEMESTRALWORK_CELL_H

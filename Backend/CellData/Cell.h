#ifndef SEMESTRALWORK_CELL_H
#define SEMESTRALWORK_CELL_H
#include "CellDataType.h"
#include "StoredData.h"
#include "FormatType.h"
#include <memory>


class Cell {
    Cell(int row, int column, const std::shared_ptr<CellDataType>& pValue);

    bool evaluateExpression();

    void formatExpression();

    void setFormat(const std::shared_ptr<FormatType> & newFormat);

    void setType();

    [[nodiscard]] std::string getOutput() const;

private:
    std::pair<int, int> position;
    std::shared_ptr<CellDataType> value;
    std::shared_ptr<FormatType> formatType;
    StoredData type = StoredData::Unknown;
    std::string output;
};

#endif //SEMESTRALWORK_CELL_H

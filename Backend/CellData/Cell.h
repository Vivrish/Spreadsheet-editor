#ifndef SEMESTRALWORK_CELL_H
#define SEMESTRALWORK_CELL_H
#include "CellDataType.h"
#include "StoredData.h"
#include "FormatType.h"
#include <memory>
#include <string>


class Cell {

public:

    Cell(int row, int column, const std::shared_ptr<CellDataType>& pValue);

    Cell(int row, int column);

    void evaluateExpression();

    void formatExpression();

    void setFormat(const std::shared_ptr<FormatType> & newFormat);

    void setType(const std::shared_ptr<CellDataType> & newType);

    void setValue(const std::string & val);

    void clear();

    [[nodiscard]] std::string getOutput() const;

    [[nodiscard]] std::string getRawOutput() const;

private:
    std::pair<int, int> position;
    std::shared_ptr<CellDataType> value;
    std::shared_ptr<FormatType> formatType;
    StoredData type = StoredData::Unknown;
    std::string output;
};

#endif //SEMESTRALWORK_CELL_H

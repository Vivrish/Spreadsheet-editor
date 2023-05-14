#ifndef SEMESTRALWORK_SPREADSHEET_H
#define SEMESTRALWORK_SPREADSHEET_H
#include <map>
#include <string>
#include <unordered_set>
#include <vector>
#include "../CellData/CellDataType.h"
#include "../File Manipulations/FileHandler.h"
#include "../CellData/FormatType.h"
#include "../Parcing/StringParser.h"


class Spreadsheet {
public:
    Spreadsheet(const Spreadsheet & source);

    Spreadsheet(std::map<std::pair<int, int>, CellDataType>);

    Spreadsheet(const InputCSVHandler & fileHandler);

    CellDataType * getData(std::pair<int, int> position);

    void addData(std::pair<int, int> position, const CellDataType & value);

    void save(FileHandler fileHandler);

    void clear();

    bool cycleCheck(std::pair<int, int> pos, std::unordered_set<std::pair<int, int>> traceback);

    bool chooseFormat(std::pair<int, int> pos, FormatType * newFormat);

    bool forceChangeType(std::pair<int, int> pos, CellDataType newType);

    friend std::ostream operator << (std::ostream & os, const Spreadsheet & spreadsheet);

private:
    std::vector<std::vector<CellDataType>> cells;
    StringParser stringParser;
};
#endif //SEMESTRALWORK_SPREADSHEET_H

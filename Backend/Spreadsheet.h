#ifndef SEMESTRALWORK_SPREADSHEET_H
#define SEMESTRALWORK_SPREADSHEET_H
#include <map>
#include <string>
#include <unordered_set>
#include <vector>
#include "CellDataType.h"
#include "File Manipulations/FileHandler.h"

class Spreadsheet {
public:
    Spreadsheet(const Spreadsheet & source);

    Spreadsheet(std::map<std::pair<int, int>, CellDataType>);

    Spreadsheet(const FileHandler & fileHandler);

    CellDataType * getData(std::pair<int, int> position);

    void addData(std::pair<int, int> position, const CellDataType & value);

    void save(FileHandler fileHandler);

    void clear();

    bool cycleCheck(std::pair<int, int>, std::unordered_set<std::pair<int, int>> traceback);

    friend std::ostream operator << (std::ostream & os, const Spreadsheet & spreadsheet);

private:
    std::vector<std::vector<CellDataType>> cells;

};
#endif //SEMESTRALWORK_SPREADSHEET_H

#ifndef SEMESTRALWORK_SPREADSHEET_H
#define SEMESTRALWORK_SPREADSHEET_H
#include <map>
#include <string>
#include <unordered_set>
#include <vector>
#include <memory>
#include "../CellData/CellDataType.h"
#include "../File Manipulations/FileHandler.h"
#include "../CellData/FormatType.h"
#include "../Parcing/StringParser.h"
#include "../CellData/Cell.h"



class Spreadsheet {
public:

    Spreadsheet();

    explicit Spreadsheet(const std::unordered_map<std::pair<int, int>, std::string> & input);

    explicit Spreadsheet(InputCSVFileHandler & fileHandler);

    explicit Spreadsheet(const std::vector<std::vector<std::string>> & input);

    void addData(const std::pair<int, int> & position, const std::string & value);

    void evaluateCell(const std::pair<int, int> & position);

    void formatCell(const std::pair<int, int> & position);

    bool cycleCheck(std::pair<int, int> pos, std::unordered_set<std::pair<int, int>, PairHash> & traceback);

    [[nodiscard]] std::vector<std::vector<std::string>> importAsVector();

    void chooseFormat(std::pair<int, int> pos, const FormatTypes &newFormat);

    void forceChangeType(std::pair<int, int> pos, const CellDataTypes &newType);

    void save(OutputCSVFileHandler & fileHandler);

    void clear();

    [[nodiscard]] std::string getData(const std::pair<int, int> & position);

    [[nodiscard]] std::string getRawData(const std::pair<int, int> & position);

    [[nodiscard]] std::vector<std::vector<std::string>> slice(std::pair<int, int> from, std::pair<int, int> to, bool pure);

    friend std::ostream & operator << (std::ostream & os, const Spreadsheet & spreadsheet);

private:

    Cell & getCell(const std::pair<int, int> & pos);

    void checkPosition(const std::pair<int, int> & pos);

    void evaluateReferences(const std::pair<int, int> & position);

    std::vector<std::vector<Cell>> cells;
    StringParser stringParser;
    std::unordered_map<std::string, std::string> constants;
};
#endif //SEMESTRALWORK_SPREADSHEET_H

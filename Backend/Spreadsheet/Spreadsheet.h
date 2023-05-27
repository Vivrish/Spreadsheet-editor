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

    explicit Spreadsheet(CSVFileHandler & fileHandler);

    explicit Spreadsheet(const std::vector<std::vector<std::string>> & input);

    void addData(const std::pair<int, int> & position, const std::string & value);

    void evaluateCell(const std::pair<int, int> & position);

    bool cycleCheck(std::pair<int, int> pos, std::unordered_set<std::pair<int, int>, PairHash> & traceback);

    [[nodiscard]] std::vector<std::vector<std::string>> importAsVector() const;

    void chooseFormat(std::pair<int, int> pos, std::shared_ptr<FormatType> & newFormat);

    void forceChangeType(std::pair<int, int> pos, std::shared_ptr<CellDataType> & newType);

    void save(CSVFileHandler & fileHandler) const;

    void clear();

    [[nodiscard]] std::string getData(const std::pair<int, int> & position);

    [[nodiscard]] std::string getRawData(const std::pair<int, int> & position);

    friend std::ostream & operator << (std::ostream & os, const Spreadsheet & spreadsheet);

private:

    Cell & getCell(const std::pair<int, int> & pos);

    static void checkPosition(const std::pair<int, int> & pos);

    void evaluateReferences(const std::pair<int, int> & position);

    std::vector<std::vector<Cell>> cells;
    StringParser stringParser;
};
#endif //SEMESTRALWORK_SPREADSHEET_H

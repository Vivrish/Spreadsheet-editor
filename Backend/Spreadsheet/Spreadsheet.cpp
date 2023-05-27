#include "Spreadsheet.h"
#include "../../Configuration/Constants.h"
#include "../Exceptions/Exceptions.h"

using namespace std;


Spreadsheet::Spreadsheet() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        cells.emplace_back();
        for (int j = 0; i < TABLE_SIZE; i++) {
            cells[i].emplace_back(i, j);
        }
    }
}

Spreadsheet::Spreadsheet(const std::vector<std::vector<std::string>> &input): Spreadsheet() {
    for (int i = 0; i < input.size(); i++) {
        for (int j = 0; j < input[i].size(); j++) {
            addData(std::pair(i, j), input[i][j]);
        }
    }
}

Spreadsheet::Spreadsheet(const std::unordered_map<std::pair<int, int>, std::string> & input): Spreadsheet() {
    for (const auto & el: input) {
        addData(el.first, el.second);
    }
}

Spreadsheet::Spreadsheet(CSVFileHandler & fileHandler): Spreadsheet(fileHandler.importAsVector()) {}

void Spreadsheet::addData(const std::pair<int, int> & position, const std::string & value) {
    if (position.first > TABLE_SIZE or position.second > TABLE_SIZE)
        throw CellOutOfBoundsException();
    getCell(position).setValue(value);
}

std::string Spreadsheet::getData(const std::pair<int, int> &position) {
    return getCell(position).getOutput();
}

std::string Spreadsheet::getRawData(const std::pair<int, int> &position) {
    return getCell(position).getRawOutput();
}

std::vector<std::vector<std::string>> Spreadsheet::importAsVector() const {
    vector<vector<string>> output;
    for (int i = 0; i < TABLE_SIZE; i++) {
        output.emplace_back();
        for (int j = 0; j < TABLE_SIZE; j++) {
            output[i].push_back(cells[i][j].getOutput());
        }
    }
    return output;
}

void Spreadsheet::save(CSVFileHandler & fileHandler) const {
    fileHandler.exportAsVector(importAsVector());
}

void Spreadsheet::clear() {
    for (const auto & row: cells) {
        for (auto column: row) {
            column.clear();
        }
    }
}

bool Spreadsheet::cycleCheck(pair<int, int> pos, unordered_set<pair<int, int>, PairHash> & traceback) {
    checkPosition(pos);
    for (const auto & el: stringParser.scoopCellReferences(getRawData(pos))) {
        // Why doesn't the unordered_set have contains() method?
        if (traceback.count(el) != 0)
            return false;
        traceback.insert(el);
        return cycleCheck(el, traceback);
    }
    return true;
}

void Spreadsheet::chooseFormat(std::pair<int, int> pos, std::shared_ptr<FormatType> &newFormat) {
    getCell(pos).setFormat(newFormat);
}

void Spreadsheet::forceChangeType(std::pair<int, int> pos, std::shared_ptr<CellDataType>& newType) {
    getCell(pos).setType(newType);
}

Cell & Spreadsheet::getCell(const std::pair<int, int> & pos) {
    checkPosition(pos);
    return cells[pos.first][pos.second];
}

void Spreadsheet::checkPosition(const std::pair<int, int> &pos) {
    if (pos.first > TABLE_SIZE or pos.second > TABLE_SIZE)
        throw CellOutOfBoundsException();
}

std::ostream & operator << (std::ostream & os, const Spreadsheet & spreadsheet) {
    for (const auto & row: spreadsheet.cells) {
        for (const auto & column: row) {
            os << column.getOutput() << "\t";
        }
        os << endl;
    }
    return os;
}

void Spreadsheet::evaluateCell(const std::pair<int, int> &position) {
    checkPosition(position);
    evaluateReferences(position);
    getCell(position).evaluateExpression();
}

void Spreadsheet::evaluateReferences(const std::pair<int, int> &position) {
    unordered_set<pair<int, int>, PairHash> traceback;
    if (not cycleCheck(position, traceback))
        throw LoopException();
    StringParser sp(getCell(position).getRawOutput());
    evaluateCell(sp.getNext());
    string value = getCell(sp.getNext()).getOutput();
    sp.replaceReferenceWithValue(value);

    while (sp.getNext() != pair<int, int>(-1,-1)) {
        evaluateCell(sp.getNext());
        value = getCell(sp.getNext()).getOutput();
        sp.replaceReferenceWithValue(value);
    }
}
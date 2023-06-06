#include "FileHandler.h"
#include <sstream>
using namespace std;


vector<std::vector<string>> InputCSVFileHandler::importAsVector() {
    vector<vector<string>> out;
    string column, row;
    stringstream ss;
    int count = 0;
    auto iter = out.end();
    while (getline(inFile, row)) {
        ss = stringstream(row);
        out.emplace_back();
        while (getline(ss, column, ',')) {
            out[count].push_back(column);
        }
        count++;
    }
    return out;
}

InputCSVFileHandler::InputCSVFileHandler(const std::string &pPath): InputFileHandler(pPath) {}


bool OutputCSVFileHandler::exportAsVector(const std::vector<std::vector<std::string>> & table) {
    if (not outFile.is_open()) return false;
    bool first;
    for (const auto & row: table) {
        first = true;
        for (const auto & column: row) {
            if (not first) outFile << ',';
            outFile << column;
            first = false;
        }
        outFile << endl;
    }
    return true;
}

OutputCSVFileHandler::OutputCSVFileHandler(const std::string &pPath): OutputFileHandler(pPath) {}


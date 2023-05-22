#include "FileHandler.h"
#include "../../Configuration/Constants.h"
#include "../Exceptions/Exceptions.h"
#include <sstream>
using namespace std;

CSVFileHandler::CSVFileHandler(const std::string & pInPath, const std::string & pOutPath): InputFileHandler(pInPath),
                                                                                         OutputFileHandler(pOutPath) {
    if (inPath.empty()) inputMode = false;
    else inputMode = true;
}

vector<std::vector<string>> CSVFileHandler::importAsVector() {
    vector<vector<string>> out;
    string column, row;
    stringstream ss;
    int count = 0;
    auto iter = out.end();
    while (getline(inFile, row)) {
        ss = stringstream(row);
        out.emplace_back();
        while (getline(ss, column, delimiter)) {
            out[count].push_back(column);
        }
        count++;
    }
    return out;
}


bool CSVFileHandler::exportAsVector(const std::vector<std::vector<std::string>> & table) {
    if (not outFile.is_open()) return false;
    bool first;
    for (const auto & row: table) {
        first = true;
        for (const auto & column: row) {
            if (not first) outFile << delimiter;
            outFile << column;
            first = false;
        }
        outFile << endl;
    }
    return true;
}

void CSVFileHandler::setDelimiter(const char & delim) {
    delimiter = delim;
}


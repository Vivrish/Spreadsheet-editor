#include "Command.h"

using namespace std;

Import::Import(const std::string &pCommand, Spreadsheet &spreadsheet): Command(pCommand, spreadsheet) {
    pattern = regex(R"(^import '[^\s\/]+(\/[^\s\/]+)*'$)");
}

void Import::extractArguments() {
    checkCommand();
    vector<string> splitArgs = split(command, ' ', '\'');
    inputCsvFileHandler = InputCSVFileHandler(splitArgs[1].substr(1, splitArgs[1].length() - 2));
}

void Import::execute() {
    inputCsvFileHandler.open();
    spreadsheet = Spreadsheet(inputCsvFileHandler);
    inputCsvFileHandler.close();
}
#include "Command.h"

using namespace std;

Save::Save(const std::string &pCommand, Spreadsheet &spreadsheet): Command(pCommand, spreadsheet) {
    pattern = regex(R"(^save '[^\s\/]+(\/[^\s\/]+)*'$)");
}

void Save::extractArguments() {
    checkCommand();
    vector<string> splitArgs = split(command, ' ', '\'');
    csvFileHandler = OutputCSVFileHandler(splitArgs[1].substr(1, splitArgs[1].length() - 2));
}

void Save::execute() {
    spreadsheet.save(csvFileHandler);
}
#include "Command.h"

using namespace std;

ChangeType::ChangeType(const std::string &pCommand, Spreadsheet &spreadsheet): Command(pCommand, spreadsheet) {
    pattern = regex("^change type '.+' of \\d+:\\d+$");
}

void ChangeType::extractArguments() {
    checkCommand();
    vector<string> splitArgs = split(command, ' ', '\'');
    dataType = CellDataType::strToTypes(splitArgs[2].substr(1, splitArgs[2].length() - 2));
    changeTypePosition = strToPair(splitArgs[4]);
}

void ChangeType::execute() {
    spreadsheet.forceChangeType(changeTypePosition, dataType);
}
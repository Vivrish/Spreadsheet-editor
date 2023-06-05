#include "Command.h"

using namespace std;

ChangeFormat::ChangeFormat(const std::string &pCommand, Spreadsheet & spreadsheet): Command(pCommand, spreadsheet) {
    pattern = regex("^change format '.+' of \\d+:\\d+$");
}

void ChangeFormat::extractArguments() {
    checkCommand();
    vector<string> splitArgs = split(command, ' ', '\'');
    formatType = FormatType::strToTypes(splitArgs[2].substr(1, splitArgs[2].length() - 2));
    changeFormatPosition = strToPair(splitArgs[4]);
}

void ChangeFormat::execute() {
    spreadsheet.chooseFormat(changeFormatPosition, formatType);
}
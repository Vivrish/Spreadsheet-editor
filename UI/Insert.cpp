#include "Command.h"

using namespace std;

Insert::Insert(const std::string &pCommand, Spreadsheet & spreadsheet): Command(pCommand, spreadsheet) {
    pattern = regex(R"(^insert '(?:[^'\\]|\\.)*' into \d+:\d+$)");
}

void Insert::extractArguments() {
    checkCommand();
    vector<string> splitArgs = split(command, ' ', '\'');
    insertValue = splitArgs[1].substr(1, splitArgs[1].length() - 2);
    insertPosition = strToPair(splitArgs[3]);
}

void Insert::execute() {
    spreadsheet.addData(insertPosition, insertValue);
    spreadsheet.evaluateCell(insertPosition);
    spreadsheet.formatCell(insertPosition);
}
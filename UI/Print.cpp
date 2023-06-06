#include "Command.h"

using namespace std;

Print::Print(const std::string &pCommand, Spreadsheet &spreadsheet): Command(pCommand, spreadsheet) {
    pattern = regex("^print range \\d+:\\d+ \\d+:\\d+ (pure|raw)$");
}

void Print::extractArguments() {
    checkCommand();
    vector<string> splitArgs = split(command, ' ', '\'');
    from = strToPair(splitArgs[2]);
    to = strToPair(splitArgs[3]);
    if (splitArgs[4] == "pure")
        pure = true;
    else pure = false;
}

void Print::execute() {
    auto cells = spreadsheet.slice(from, to, pure);
    for (const auto & row: cells) {
        for (const auto & column: row) {
            output += column + "\t";
        }
        output += "\n";
    }
}
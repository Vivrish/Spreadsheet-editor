#include "Command.h"


using namespace std;

Command::Command(const std::string &pCommand, Spreadsheet & pSpreadsheet): spreadsheet(pSpreadsheet) {
    command = pCommand;
}

std::string Command::getOutput() const {
    return output;
}

void Command::checkCommand() {
    if (not regex_match(command, pattern))
        throw InvalidCommandException();
}
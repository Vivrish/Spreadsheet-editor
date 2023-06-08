#include "Command.h"

using namespace std;

Clear::Clear(const std::string &pCommand, Spreadsheet &spreadsheet): Command(pCommand, spreadsheet) {
    pattern = regex("^clear$");
}

void Clear::extractArguments() {
    checkCommand();
}

void Clear::execute() {
    spreadsheet.clear();
}
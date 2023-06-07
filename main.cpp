#include <iostream>
#include <fstream>
#include <unordered_map>
#include <vector>
#include "UI/CommandHandler.h"

using namespace std;

int main() {
    Spreadsheet spreadsheet;
    CommandHandler commandHandler(spreadsheet);
    commandHandler.begin();

    cout << "You have exited the program. Goodbye" << endl;

    return 0;
}

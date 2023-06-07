#include <iostream>
#include <csignal>
#include "Tests/Tests.h"


using namespace std;

void signalHandler(int signal) {
    if (signal == SIGINT)
        cout << "SIGINT detected. Program is not responsible for any memory leaks from now.";
    exit(signal);
}

int execute() {
    signal(SIGINT, signalHandler);

    try {
        Spreadsheet spreadsheet;
        CommandHandler commandHandler(spreadsheet);
        commandHandler.listen();
    }
    catch (BadConfigException &) {
        cout << "Config format is invalid. I'll remind you that Config.txt should contain four key:'value' pairs."
                "Do not change key signatures (NAME_OF_CREATED_TABLE, PADDING, TABLE_SIZE, CELL_SIZE)."
                "Provide positive integers for TABLE_SIZE and CELL_SIZE no more than 10000 and 100 accordingly" << endl;
    }


    cout << "You have exited the program. Goodbye" << endl;

    return 0;
}

int main() {
    testAll();
    return 0;
}

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
        cout << "Config format is invalid. I'll remind you that Config.txt should contain three key:'value' pairs."
                "Do not change key signatures (PADDING, TABLE_SIZE, CELL_SIZE)."
                "Provide positive integers for TABLE_SIZE and CELL_SIZE no more than 10000 and 100 accordingly" << endl;
    }
    catch (...) {
        cout << "Unexpected behaviour. Exiting the program" << endl;
        return 1;
    }


    cout << "You have exited the program. Goodbye" << endl;

    return 0;
}

int main() {
    return execute();
}

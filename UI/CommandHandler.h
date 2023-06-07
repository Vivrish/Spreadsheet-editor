#ifndef SEMESTRALWORK_COMMANDHANDLER_H
#define SEMESTRALWORK_COMMANDHANDLER_H
#include "Command.h"
#include <memory>

class CommandHandler {
public:
    explicit CommandHandler(Spreadsheet & pSpreadsheet);

    void listen();

private:

    std::shared_ptr<Command> getCommand();

    std::string userInput;
    Spreadsheet & spreadsheet;
};


#endif //SEMESTRALWORK_COMMANDHANDLER_H

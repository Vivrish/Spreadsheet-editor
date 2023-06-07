#include "CommandHandler.h"

using namespace std;

CommandHandler::CommandHandler(Spreadsheet &pSpreadsheet): spreadsheet(pSpreadsheet) {}

void CommandHandler::begin() {
    shared_ptr<Command> command;
    while (true) {
        cout << "Please, enter a command: " << endl;
        cin >> userInput;
        if (cin.eof() or regex_match(userInput, regex("^exit$"))) {
            break;
        }
        try {
            command = getCommand();
        }
        catch (InvalidCommandException &) {
            cout
                    << "You entered an invalid command. Please, try again. If you are confused and don't know any commands, write 'help' for instructions"
                    << endl;
            continue;
        }
        command->extractArguments();
        command->execute();
        cout << "Command has been executed successfully. Nice job" << endl;

    }
}

std::shared_ptr<Command> CommandHandler::getCommand() {
    regex changeFormatMatch("^change format '.+' of \\d+:\\d+$"),
            changeTypeMatch("^change type '.+' of \\d+:\\d+$"),
            clearMatch("^clear$"),
            importMatch(R"(^import '[^\s\/]+(\/[^\s\/]+)*'$)"),
            insertMatch(R"(^insert '(?:[^'\\]|\\.)*' into \d+:\d+$)"),
            printMatch(R"(^print range \d+:\d+ \d+:\d+ (pure|raw)$)"),
            saveMatch(R"(^save '[^\s\/]+(\/[^\s\/]+)*'$)"),
            helpMatch("^help$");
    if (regex_match(userInput, changeFormatMatch))
        return make_shared<ChangeFormat>(userInput, spreadsheet);
    else if (regex_match(userInput, changeTypeMatch))
        return make_shared<ChangeType>(userInput, spreadsheet);
    else if (regex_match(userInput, clearMatch))
        return make_shared<Clear>(userInput, spreadsheet);
    else if (regex_match(userInput, importMatch))
        return make_shared<Import>(userInput, spreadsheet);
    else if (regex_match(userInput, insertMatch))
        return make_shared<Insert>(userInput, spreadsheet);
    else if (regex_match(userInput, printMatch))
        return make_shared<Print>(userInput, spreadsheet);
    else if (regex_match(userInput, saveMatch))
        return make_shared<Save>(userInput, spreadsheet);
    else if (regex_match(userInput, helpMatch))
        return make_shared<Help>(userInput, spreadsheet);
    throw InvalidCommandException();
}
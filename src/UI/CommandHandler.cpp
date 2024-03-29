#include "CommandHandler.h"

using namespace std;

CommandHandler::CommandHandler(Spreadsheet &pSpreadsheet): spreadsheet(pSpreadsheet) {}

void CommandHandler::listen() {
    shared_ptr<Command> command;
    while (true) {
        cout << "Please, enter a command: " << endl;
        getline(cin, userInput);
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
        try {
            command->extractArguments();
        }
        catch (out_of_range &) {
            cout << "Provide numbers that int can hold. Try again" << endl;
            continue;
        }
        try {
            command->execute();
        }
        catch (InvalidOperationException &) {
            cout << "Seems like you have not entered the data to one of the cells according to the rules. Change it and try again." << endl;
            continue;
        }
        catch (CellOutOfBoundsException &) {
            cout << "That's too big of a number for a cell. Try again" << endl;
            continue;
        }
        catch (IncorrectAmountOfArgumentsException &) {
            cout << "Unable to calculate one of the cells. Check data types and syntax" << endl;
            continue;
        }
        catch (FileIsNotOpenedException &) {
            cout << "No such file exist in the directory. Try again" << endl;
            continue;
        }
        catch (CannotCreateTheFileException &) {
            cout << "Cannot create file with such path. Try again" << endl;
            continue;
        }
        catch (LoopException &) {
            cout << "You have a reference loop among the cells. Find and resolve it" << endl;
            continue;
        }
        catch (MismatchedParenthesisException &) {
            cout << "You messed up some parentheses. Find and resolve it" << endl;
            continue;
        }
        catch (FormatDataMismatchException &) {
            cout << "Format does not make sense for data type in one of the cells. Find and resolve it" << endl;
            continue;
        }
        catch (invalid_argument &) {
            cout << "Unable to calculate one of the cells. Check data types and syntax" << endl;
            continue;
        }
        catch (...) {
            cout << "Something went wrong. Try again" << endl;
            continue;
        }

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
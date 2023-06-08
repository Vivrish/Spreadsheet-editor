#ifndef SEMESTRALWORK_COMMAND_H
#define SEMESTRALWORK_COMMAND_H

#include <string>
#include <regex>
#include <vector>

#include "../Backend/Exceptions/Exceptions.h"
#include "../Backend/Spreadsheet/Spreadsheet.h"

class Command {
public:

    Command(const std::string & pCommand, Spreadsheet & spreadsheet);

    virtual void execute() = 0;

    virtual void extractArguments() = 0;

    virtual void checkCommand();

    [[nodiscard]] virtual std::string getOutput() const;

protected:
    Spreadsheet & spreadsheet;
    std::vector<std::string> arguments;
    std::string command;
    std::string output;
    std::regex pattern;
};


class Insert: public Command {
public:
    Insert(const std::string & pCommand, Spreadsheet & spreadsheet);

    void execute() override;

    void extractArguments() override;
private:
    std::pair<int, int> insertPosition;
    std::string insertValue;
};

class ChangeFormat: public Command {
public:
    ChangeFormat(const std::string & pCommand, Spreadsheet & spreadsheet);

    void execute() override;

    void extractArguments() override;

private:
    std::pair<int, int> changeFormatPosition;
    FormatTypes formatType = FormatTypes::UNKNOWN;
};

class ChangeType: public Command {
public:
    ChangeType(const std::string & pCommand, Spreadsheet & spreadsheet);

    void execute() override;

    void extractArguments() override;
private:
    std::pair<int, int> changeTypePosition;
    CellDataTypes dataType = CellDataTypes::UNKNOWN;
};

class Print: public Command {
public:
    Print(const std::string & pCommand, Spreadsheet & spreadsheet);

    void execute() override;

    void extractArguments() override;

private:
    std::pair<int, int> from;
    std::pair<int, int> to;
    bool pure = true;
};

class Save: public Command {
public:
    Save(const std::string & pCommand, Spreadsheet & spreadsheet);

    void execute() override;

    void extractArguments() override;

private:
    OutputCSVFileHandler csvFileHandler;
};

class Import: public Command {
public:
    Import(const std::string & pCommand, Spreadsheet & spreadsheet);

    void execute() override;

    void extractArguments() override;
private:
    InputCSVFileHandler inputCsvFileHandler;
};

class Clear: public Command {
public:
    Clear(const std::string & pCommand, Spreadsheet & spreadsheet);

    void execute() override;

    void extractArguments() override;
};

class Help: public Command {
public:
    Help(const std::string & pCommand, Spreadsheet & spreadsheet);

    void execute() override;

    void extractArguments() override;
};


#endif //SEMESTRALWORK_COMMAND_H

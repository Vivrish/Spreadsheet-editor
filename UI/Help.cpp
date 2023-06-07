#include "Command.h"

using namespace std;


Help::Help(const std::string &pCommand, Spreadsheet &spreadsheet): Command(pCommand, spreadsheet) {
    pattern = regex("^help$");
}


void Help::extractArguments() {
    checkCommand();
}

void Help::execute() {
    cout << "Hello, this is a spreadsheet program. Here's some possibilities, rules, notation and available commands: " << endl;
    cout << "Possibilities:" << endl;
    cout << "You are free to make a spreadsheet of your own size and choose, how many symbols each cell is able to show."
            "You can choose between numeric and string data types, based on which the program will perform arithmetic "
            "operations. On top of that you can choose, how you want your data to be represented: date, time, float, integer "
            "and boolean for numeric type and left padding, right padding (which you also choose), string that contains "
            "only one space in a row, string without trailing and leading whitespaces and just a plain string. You can "
            "reference other cells if you want to, but be careful and don't create a loop. In order to look at your "
            "table you can print part of it or direct it to a .csv file. You can of course import data from .csv file to "
            "your spreadsheet." << endl << endl;
    cout << "Rules: " << endl;
    cout << "1. Always use a whitespace after every operation, operand or parentheses within a cell."
            " Example: 'sin ( 32 ) + 13:11 ^ 2'" << endl;
    cout << "2. Do not create loops via references" << endl;
    cout << "3. Always mark strings with \"\" clause" << endl;
    cout << "4. Do not assign string format type to numeric data type and vice versa" << endl;
    cout << "5. Do not try to create too big of a spreadsheet (table size > 10000 or cell size > 100)" << endl;
    cout << "6. Do not violate the format of Config.txt (key:'value')" << endl;
    cout << "7. Do not try to perform operations that don't make sense like '\"cat\" ^ 2'";
    cout << "8. Do not perform numeric operations within string cell and vice versa" << endl;
    cout << endl;
    cout << "Notation: " << endl;
    cout << "Format types: boolean, date, time, integer, float, max one space string, pad left string, pad right string,"
            "pure string, stripped string" << endl;
    cout << "Cell data types: numeric, string" << endl;
    cout << "Cell number format: <row>:<column>" << endl;
    cout << "Operators: + - * / ^" << endl;
    cout << "Formulas: sin cos strip" << endl;
    cout << "Reference: <row number>:<column number>" << endl;
    cout << "Available combinations: string + string, number + number, string - string (delete first occurrence of second "
            "string in first one), number - number, string * number, number * number, string / string (delete all occurrences of second"
            "string in first one), number / number, number ^ number, sin ( number ), cos ( number ), strip ( string )"
            " (delete leading and trailing whitespaces)" << endl << endl;

    cout << "Available commands: " << endl;
    cout << "change format '<newFormat>' of <cellNumber>" << endl;
    cout << "change type '<newType>' of <cellNumber>" << endl;
    cout << "clear" << endl;
    cout << "help" << endl;
    cout << "import '<path>'" << endl;
    cout << "insert '<value>' into <cellNumber>" << endl;
    cout << "print range <beginCellNumber> <endCellNumber> <pure or raw>" << endl;
    cout << "save '<path>'" << endl;
    cout << "exit" << endl;
}
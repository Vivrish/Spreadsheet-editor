#include <iostream>
#include <fstream>
#include <unordered_map>
#include <vector>
#include "UI/Command.h"

using namespace std;

int main() {

    string test = " 123:4567  123:1233  \"1:1\" ";

    queue<pair<int, int>> tres = getOrderedReferences(test);
    queue<string> values;
    values.emplace("a");
    values.emplace("b");
    values.emplace("c");
    replaceReferencesWithValues(test, values);

    Spreadsheet spreadsheet;


    spreadsheet.addData({1, 1}, "10");
    spreadsheet.forceChangeType({1,1}, CellDataTypes::NUMERIC);
    spreadsheet.evaluateCell({1, 1});
    spreadsheet.chooseFormat({1,1}, FormatTypes::INTEGER);
    spreadsheet.formatCell({1,1});

    spreadsheet.addData({1,2}, "777 + 1:1");
    spreadsheet.forceChangeType({1,2}, CellDataTypes::NUMERIC);
    spreadsheet.evaluateCell({1, 2});
    spreadsheet.chooseFormat({1,2}, FormatTypes::INTEGER);
    spreadsheet.formatCell({1,2});


    ChangeFormat changeFormat("change format 'pad left string' of 2:3", spreadsheet);
    changeFormat.extractArguments();
    changeFormat.execute();

    ChangeType changeType("change type 'string' of 2:3", spreadsheet);
    changeType.extractArguments();
    changeType.execute();

    Insert insert("insert \'\"Groomy\"\' into 2:3", spreadsheet);
    insert.extractArguments();
    insert.execute();

    auto sl = spreadsheet.slice({1,1}, {3, 3}, true);

    Print print("print range 1:1 3:3 raw", spreadsheet);
    print.extractArguments();
    print.execute();


    Save save("save 'goofy.txt'", spreadsheet);
    save.extractArguments();
    save.execute();

    Import imp("import 'C:\\Users\\Admin\\CLionProjects\\SemestralWork\\cmake-build-debug\\goofy.txt'", spreadsheet);
    imp.extractArguments();
    imp.execute();

   cout << spreadsheet;

    return 0;
}

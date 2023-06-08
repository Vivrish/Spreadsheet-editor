#include "Tests.h"

using namespace std;


void testParsing() {
    StringParser sp;

    sp.parse("sin ( 1 ) + cos ( 2 ) - 3 * 4 / 5 ^ 6");
    queue<string> tmp = sp.getOutput();
    assert(queueToString(tmp) == "1 sin 2 cos + 3 4 * 5 6 ^ / -");
    // Don't need to compare doubles here
    assert(to_string(sp.getAST()->getNumericResult()) == "0.424556");
    sp.parse("    ");
    tmp = sp.getOutput();
    assert(queueToString(tmp).empty());

    sp.parse("");
    tmp = sp.getOutput();
    assert(queueToString(tmp).empty());

    sp.parse(R"(( "string" * 13 ) + " some more string" / "more" - "string")");
    tmp = sp.getOutput();
    assert(queueToString(tmp) == "\"string\" 13 * \" some more string\" \"more\" / + \"string\" -");
    assert(sp.getAST()->getStringResult() ==
           "\"stringstringstringstringstringstringstringstringstringstringstringstring some  string\"");

//    stack<string> st;
//    st.emplace("sdfsedf");
//    clearStack(st);
//    assert(st.empty());
//
    queue<string> q;
//    q.emplace("fsdfds");
//    clearQueue(q);
//    assert(q.empty());

//    st.emplace("first");
//    st.emplace("second");
//    assert(getSecondFromTop(st) == "second");

    q.emplace("first");
    q.emplace("second");
    assert(queueToString(q) == "first second");

    string text = "\"Plain text\" not plain text";
    assert(removePlainText(text) == " not plain text");

    assert(parsePair("12321:432553") == make_pair(12321, 432553));

    text = "( 13 + 213 ) ^ 231 + \"Do not split between quotation marks\" - 43 * sin ( 0 )";
    assert(split(text, ' ', '\"') == vector<string>(
            {"(", "13", "+", "213", ")", "^", "231", "+", "\"Do not split between quotation marks\"", "-", "43", "*",
             "sin", "(", "0", ")"}));

    text = "          a        lot       of      spaces       ";
    assert(trimSpaces(text) == " a lot of spaces ");

    assert(not isNumber("\"13\""));
    assert(isNumber("13"));
    assert(isString("\"13\""));
    assert(not isString("13"));
    assert(isOperator("+"));
    assert(not isOperator("13"));
    assert(isOperand("13"));
    assert(not isOperand("*"));
    assert(isFunction("sin"));
    assert(not isFunction("+"));
    assert(insideQuotations("01234\"6\"89", 6));
    assert(not insideQuotations("01234\"6\"89", 8));
    assert(strToPair("1323:2342") == make_pair(1323, 2342));

    text = "0:0 \"1:1\" 2:2";
    unordered_set<pair<int, int>, PairHash> refs = {make_pair(0, 0), make_pair(2, 2)};
    assert(refs == scoopCellReferences(text));

    queue<pair<int, int>> order;
    order.emplace(0, 0);
    order.emplace(2, 2);
    assert(getOrderedReferences(text) == order);

    queue<string> values;
    values.emplace("first value");
    values.emplace("second value");
    replaceReferencesWithValues(text, values);

    assert(text == "first value \"1:1\" second value");

}

void testOperators() {
    shared_ptr<Operator> op = make_shared<Divide>();
    op->addArgument(2);
    op->addArgument(1024);
    assert(op->calculateNum() == 512);

    op = make_shared<Divide>();
    op->addArgument("\"str\"");
    op->addArgument("\"strstrstrstrSomething differentstr strstr\"");
    assert(op->calculateStr() == "\"Something different \"");

    op = make_shared<Minus>();
    op->addArgument(2);
    op->addArgument(1024);
    assert(op->calculateNum() == 1022);

    op = make_shared<Minus>();
    op->addArgument("\"str\"");
    op->addArgument("\"strstrstrstrSomething differentstr strstr\"");
    assert(op->calculateStr() == "\"strstrstrSomething differentstr strstr\"");

    op = make_shared<Multiply>();
    op->addArgument(2);
    op->addArgument(1024);
    assert(op->calculateNum() == 2048);

    op = make_shared<Multiply>();
    op->addArgument(2);
    op->addArgument("\"str\"");
    assert(op->calculateStr() == "\"strstr\"");

    op = make_shared<Plus>();
    op->addArgument(2);
    op->addArgument(1024);
    assert(op->calculateNum() == 1026);

    op = make_shared<Plus>();
    op->addArgument("\"str\"");
    op->addArgument("\"str\"");
    assert(op->calculateStr() == "\"strstr\"");

    op = make_shared<Power>();
    op->addArgument(10);
    op->addArgument(2);
    assert(op->calculateNum() == 1024);

}

void testFormulas() {
    shared_ptr<Formula> formula = make_shared<Sin>();
    formula->addArgument(0);
    assert(formula->calculateNum() == 0);

    formula = make_shared<Cos>();
    formula->addArgument(0);
    assert(formula->calculateNum() == 1);

    formula = make_shared<Strip>();
    formula->addArgument("       word       ");
    assert(formula->calculateStr() == "word");
}

void polymorphicTest() {
    shared_ptr<FormatType> ptr = make_shared<Date>("200");
    ptr->format();
    assert(ptr->getFormattedValue() == "20/7/1970");

    ptr = make_shared<Time>("3600");
    ptr->format();
    assert(ptr->getFormattedValue() == "1:0:0");

    ptr = make_shared<Boolean>("0");
    ptr->format();
    assert(ptr->getFormattedValue() == "false");

    ptr = make_shared<Float>("3.14159265358");
    ptr->format();
    assert(ptr->getFormattedValue() == "3.141593");

    ptr = make_shared<Integer>("3.14159265358");
    ptr->format();
    assert(ptr->getFormattedValue() == "3");

    ptr = make_shared<MaxOneSpaceString>("      Word  word word       Word        ");
    ptr->format();
    assert(ptr->getFormattedValue() == " Word word word Word ");

    ptr = make_shared<PadLeftString>("Word");
    ptr->format();
    assert(ptr->getFormattedValue() == ptr->constants["PADDING"] + "Word");

    ptr = make_shared<PadRightString>("Word");
    ptr->format();
    assert(ptr->getFormattedValue() == "Word" + ptr->constants["PADDING"]);

    ptr = make_shared<PureString>("Word");
    ptr->format();
    assert(ptr->getFormattedValue() == "Word");

    ptr = make_shared<StrippedString>("  Word       ");
    ptr->format();
    assert(ptr->getFormattedValue() == "Word");

    shared_ptr<CellDataType> cellDataType = make_shared<Numeric>();
    cellDataType->setEvaluatedReferences("13 + 8");
    cellDataType->evaluate();
    assert(cellDataType->getResult() == "21.000000");

    cellDataType = make_shared<String>();
    cellDataType->setEvaluatedReferences(R"("String one " + "String two")");
    cellDataType->evaluate();
    assert(cellDataType->getResult() == "\"String one String two\"");
}

void testFiles() {

}

void cellTest() {
    Cell cell(0, 0, make_shared<Numeric>("2 ^ 2 ^ 2 ^ sin ( 2 )"));
    assert(cell.getRawOutput() == "2 ^ 2 ^ 2 ^ sin ( 2 )");
    cell.setFormat(make_shared<Float>());
    cell.setEvaluatedReferences(cell.getRawOutput());
    cell.evaluateExpression();
    cell.formatExpression();
    assert(cell.getOutput() == "12.781493");
    cell.setType(make_shared<String>(R"("Value" - "ue")"));
    cell.setEvaluatedReferences(cell.getRawOutput());
    cell.setFormat(make_shared<PureString>());
    cell.evaluateExpression();
    cell.formatExpression();
    assert(cell.getOutput() == "\"Val\"");
}

void testFiles() {
    OutputCSVFileHandler outputCsvFileHandler("Table.csv");
    outputCsvFileHandler.create();
    outputCsvFileHandler.exportAsVector({{"\"one\"", "\"two\""}, {"\"three\"", "\"four\""}});
    outputCsvFileHandler.shut();

    InputCSVFileHandler inputCsvFileHandler("Table.csv");
    inputCsvFileHandler.open();
    vector<vector<string>> test = {{"\"one\"", "\"two\""}, {"\"three\"", "\"four\""}};
    assert(inputCsvFileHandler.importAsVector() == test);
    inputCsvFileHandler.close();
}

void testCellData() {
    polymorphicTest();
    cellTest();
}

void testAll() {
    testCellData();
    testFormulas();
    testOperators();
    testParsing();
    testFiles();
}
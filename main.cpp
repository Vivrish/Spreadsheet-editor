#include <iostream>
#include <fstream>
#include <unordered_map>
#include <vector>
#include "Backend/Spreadsheet/Spreadsheet.h"

using namespace std;

int main() {
    Spreadsheet spreadsheet;

    spreadsheet.addData({1,2}, "Here");

    cout << spreadsheet;

    return 0;
}

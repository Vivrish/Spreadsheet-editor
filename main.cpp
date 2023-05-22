#include <iostream>
#include <fstream>
#include <unordered_map>
#include <vector>
#include "Backend/File Manipulations/FileHandler.h"

using namespace std;

int main() {
    ConfigFileHandler configFileHandler("/home/nikolai/CLionProjects/SemestralWork/Configuration/Config.txt");

    cout << configFileHandler.open();
    unordered_map<string, string> res = configFileHandler.importAsMap();

    configFileHandler.close();
    return 0;
}

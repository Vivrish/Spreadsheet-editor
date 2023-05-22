#include <string>
#include <sstream>
#include "FileHandler.h"
#include "../Exceptions/Exceptions.h"


using namespace std;

ConfigFileHandler::ConfigFileHandler(const std::string &pInPath): InputFileHandler(pInPath) {}

std::unordered_map<std::string, std::string> ConfigFileHandler::importAsMap() {
    unordered_map<string, string> out;
    string line, key, value;
    while (getline(inFile, line)) {
        stringstream ss(line);
        if (not getline(ss, key, ':') or not getline(ss, value, ':'))
            throw BadConfigFormatException();
        out[key] = value;
    }
    return out;
}

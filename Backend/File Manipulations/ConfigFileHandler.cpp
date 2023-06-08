#include <string>
#include <sstream>
#include "FileHandler.h"
#include "../Exceptions/Exceptions.h"



using namespace std;

ConfigFileHandler::ConfigFileHandler(const std::string &pInPath) : InputFileHandler(pInPath) {}

void ConfigFileHandler::generateMap() {
    string line, key, value;
    while (getline(inFile, line)) {
        stringstream ss(line);
        if (not getline(ss, key, ':') or not getline(ss, value, ':'))
            throw BadConfigFormatException();
        if (value.back() != '\'' or value.front() != '\'')
            throw BadConfigException();
        conf[key] = value.substr(1, value.length() - 2);
    }
}


void ConfigFileHandler::checkMap() {
    if (conf.count("PADDING") == 0 or
        conf.count("TABLE_SIZE") == 0 or
        conf.count("CELL_SIZE") == 0)
        throw BadConfigException();
    try {
        if (stoi(conf["TABLE_SIZE"]) > 10000 or stoi(conf["CELL_SIZE"]) > 100)
            throw BadConfigException();
    }
    catch (std::invalid_argument &) {
        throw BadConfigException();
    }
}

std::unordered_map<std::string, std::string> ConfigFileHandler::getConf() const {
    return conf;
}


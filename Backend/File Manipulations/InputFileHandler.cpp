#include "FileHandler.h"
#include "../Exceptions/Exceptions.h"

InputFileHandler::InputFileHandler(const std::string &pPath) {
    inPath = pPath;
}

bool InputFileHandler::open() {
    if (inFile.is_open()) throw FileAlreadyOpenedException();
    inFile.open(inPath);
    return inFile.is_open();
}

bool InputFileHandler::close() {
    if (inFile.is_open()) inFile.close();
    //todo
    // Should it throw exception when file cannot be closed?
}


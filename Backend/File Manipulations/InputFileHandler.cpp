#include "FileHandler.h"
#include "../Exceptions/Exceptions.h"

InputFileHandler::InputFileHandler(const std::string &pPath): FileHandler() {
    inPath = pPath;
}

void InputFileHandler::open() {
    if (inFile.is_open())
        throw FileAlreadyOpenedException();
    inFile.open(inPath);
    if (not inFile.is_open())
        throw FileIsNotOpenedException();
}

void InputFileHandler::close() {
    if (inFile.is_open()) {
        inFile.close();
    }
}


#include "FileHandler.h"


using namespace std;

OutputFileHandler::OutputFileHandler(const std::string & pPath): FileHandler() {
    outPath = pPath;
}


void OutputFileHandler::create() {
    outFile.open(outPath, ofstream::out);
    if (outFile.is_open())
        throw CannotCreateTheFileException();
}

void OutputFileHandler::shut() {
    if (not outFile.is_open())
        return;
    outFile.close();
}


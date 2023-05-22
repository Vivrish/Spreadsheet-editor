#include "FileHandler.h"


using namespace std;

OutputFileHandler::OutputFileHandler(const std::string & pPath) {
    outPath = pPath;
}


bool OutputFileHandler::create() {
    outFile.open(outPath, ofstream::out);
    return outFile.is_open();
}

bool OutputFileHandler::shut() {
    if (not outFile.is_open()) return false;
    outFile.close();
    return true;
}


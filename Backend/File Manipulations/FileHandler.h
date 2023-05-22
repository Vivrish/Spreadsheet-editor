#ifndef SEMESTRALWORK_FILEHANDLER_H
#define SEMESTRALWORK_FILEHANDLER_H
#include <string>
#include <ostream>
#include <fstream>
#include <vector>
#include <unordered_map>

class InputFileHandler {
public:
    explicit InputFileHandler(const std::string & pPath);

    bool close();

    bool open();
protected:
    std::string inPath;
    std::fstream inFile;

};

class OutputFileHandler {
public:
    explicit OutputFileHandler(const std::string & pPath);

    bool create();

    bool shut();

protected:
    std::string outPath;
    std::fstream outFile;
};

class CSVFileHandler: public InputFileHandler, public OutputFileHandler {
public:
    CSVFileHandler(const std::string & pInPath, const std::string & pOutPath);
    std::vector<std::vector<std::string>> importAsVector();
    bool exportAsVector(const std::vector<std::vector<std::string>>& table);
    void setDelimiter(const char & delim);
    void switchToOutMode(const std::string & pOutPath);

private:
    char delimiter = ',';
    bool inputMode;
};
class ConfigFileHandler: public InputFileHandler {
public:

    explicit ConfigFileHandler(const std::string & pInPath);

    std::unordered_map<std::string, std::string> importAsMap();

};



#endif //SEMESTRALWORK_FILEHANDLER_H

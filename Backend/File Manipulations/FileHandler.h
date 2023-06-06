#ifndef SEMESTRALWORK_FILEHANDLER_H
#define SEMESTRALWORK_FILEHANDLER_H
#include <string>
#include <ostream>
#include <fstream>
#include <vector>
#include <unordered_map>

class InputFileHandler {
public:
    InputFileHandler() = default;

    explicit InputFileHandler(const std::string & pPath);

    void close();

    void open();
protected:
    std::string inPath;
    std::fstream inFile;

};

class OutputFileHandler {
public:
    OutputFileHandler() = default;
    explicit OutputFileHandler(const std::string & pPath);

    bool create();

    bool shut();

protected:
    std::string outPath;
    std::fstream outFile;
};

class ConfigFileHandler: public InputFileHandler {
public:

    explicit ConfigFileHandler(const std::string & pInPath);

    void generateMap();

    void checkMap();

    std::unordered_map<std::string, std::string> getConf() const;
private:
    std::unordered_map<std::string, std::string> conf;
};

class InputCSVFileHandler: public InputFileHandler {
public:
    InputCSVFileHandler() = default;
    explicit InputCSVFileHandler(const std::string & pPath);
    std::vector<std::vector<std::string>> importAsVector();
};

class OutputCSVFileHandler: public OutputFileHandler {
public:
    OutputCSVFileHandler() = default;
    explicit OutputCSVFileHandler(const std::string & pPath);
    bool exportAsVector(const std::vector<std::vector<std::string>>& table);
};



#endif //SEMESTRALWORK_FILEHANDLER_H

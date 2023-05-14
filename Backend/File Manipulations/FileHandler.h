#ifndef SEMESTRALWORK_FILEHANDLER_H
#define SEMESTRALWORK_FILEHANDLER_H
#include <string>
#include <ostream>
#include <fstream>
#include <vector>
#include <unordered_map>

class FileHandler {
public:
    FileHandler(const std::string & pPath, bool isInput);

    bool open();

    bool close();


    std::string path;
    std::fstream inFile;
    std::ofstream outFile;
};

class CSVFileHandler: public FileHandler {

    std::vector<std::vector<std::string>> importAsVector();

    bool exportAsVector();

private:
    std::vector<std::vector<std::string>> table;
};
class ConfigFileHandler: public FileHandler {

    std::unordered_map<std::string, std::string> importAsMap();

};



#endif //SEMESTRALWORK_FILEHANDLER_H

#ifndef SEMESTRALWORK_FILEHANDLER_H
#define SEMESTRALWORK_FILEHANDLER_H
#include <string>
#include <ostream>
#include <fstream>
#include <vector>
#include <unordered_map>

class FileHandler {
    FileHandler(const std::string & pPath);

    bool open();

    bool close();

protected:
    std::string path;
};

class InputFileHandler: public FileHandler {

    bool makeCopy(std::string path);

    virtual bool read();

protected:
    std::ostream file;
};

class OutputFileHandler: FileHandler {
public:
    bool create();
protected:
    std::fstream file;
};

class OutputCSVHandler: public OutputFileHandler {

    bool write(std::vector<std::vector<std::string>> table);

};

class InputCSVHandler: public InputFileHandler {
public:
    std::vector<std::vector<std::string>> importAsVector() const;

    bool makeVector();

protected:
    std::vector<std::vector<std::string>> table;
};

class ConfigHandler: public InputFileHandler{
public:
    std::unordered_map<std::string, std::string> importAsMap() const;

    bool makeMap();

protected:
    std::unordered_map<std::string, std::string> config;
};



#endif //SEMESTRALWORK_FILEHANDLER_H

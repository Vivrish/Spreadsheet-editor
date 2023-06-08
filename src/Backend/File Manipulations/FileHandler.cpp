#include "FileHandler.h"


FileHandler::FileHandler() {
    ConfigFileHandler configFileHandler("../Configuration/Config.txt");
    configFileHandler.open();
    configFileHandler.generateMap();
    configFileHandler.checkMap();
    constants = configFileHandler.getConf();
    configFileHandler.close();
}
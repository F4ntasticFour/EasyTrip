#ifndef EASYTRIP_FILEHANDLER_H
#define EASYTRIP_FILEHANDLER_H

#include <string>
#include <fstream>
#include "Queue.h"


class FileHandler {
    std::string fileName;
public:
    FileHandler(std::string fileName);
    std::string getFileName();
    int getBusData();
    Queue<std::string> getEventList();
    int getStationData();
    int getCheckupData();

};



#endif //EASYTRIP_FILEHANDLER_H

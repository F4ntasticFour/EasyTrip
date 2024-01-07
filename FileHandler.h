#ifndef EASYTRIP_FILEHANDLER_H
#define EASYTRIP_FILEHANDLER_H

#include <string>
#include <vector>
#include "CompanyClass.h"  // Include your main simulation class
#include "Queue.h"
class FileHandler {
private:
    std::string fileName;
    std::vector<std::string> fileContents;

    void readFileContents();

public:
    explicit FileHandler(std::string fileName);

    int getNumStations();

    int getTimeBetweenStations();

    int getGetOnOffTime();

    int getMaxW();

    int getC_MBus();

    int getC_WBus();

    int getJ();

    int getMBusCapacity();

    int getWBusCapacity();

    int getMBusCount();

    int getWBusCount();

    Queue<std::vector<std::string>> processEventLines();

    int getNumEvents();

    void writeToFile(Queue<PassengerClass*>& passengers);
};

#endif //EASYTRIP_FILEHANDLER_H
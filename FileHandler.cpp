#include "FileHandler.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include "Queue.h"


// Constructor and other methods...
FileHandler::FileHandler(std::string fileName) {
    this->fileName = std::move(fileName);
    readFileContents();
}
void FileHandler::readFileContents() {
    std::ifstream file(fileName);
    std::string line;
    while (std::getline(file, line)) {
        fileContents.push_back(line);
    }
    file.close();
}
int FileHandler::getNumStations() {
    std::istringstream ss1(fileContents[0]);
    int numStations, timeBetweenStations;
    ss1 >> numStations >> timeBetweenStations;
    return numStations;
}
int FileHandler::getTimeBetweenStations() {
    std::istringstream ss1(fileContents[0]);
    int numStations, timeBetweenStations;
    ss1 >> numStations >> timeBetweenStations;
    return timeBetweenStations;
}
int FileHandler::getWBusCount() {
    std::istringstream ss2(fileContents[1]);
    int WBus_count, MBus_count;
    ss2 >> WBus_count >> MBus_count;
    return WBus_count;
}
int FileHandler::getMBusCount() {
    std::istringstream ss2(fileContents[1]);
    int WBus_count, MBus_count;
    ss2 >> WBus_count >> MBus_count;
    return MBus_count;
}
int FileHandler::getWBusCapacity() {
    std::istringstream ss3(fileContents[2]);
    int WBus_capacity, MBus_capacity;
    ss3 >> WBus_capacity >> MBus_capacity;
    return WBus_capacity;
}
int FileHandler::getMBusCapacity() {
    std::istringstream ss3(fileContents[2]);
    int WBus_capacity, MBus_capacity;
    ss3 >> WBus_capacity >> MBus_capacity;
    return MBus_capacity;
}
int FileHandler::getJ() {
    std::istringstream ss4(fileContents[3]);
    int J, C_WBus, C_MBus;
    ss4 >> J >> C_WBus >> C_MBus;
    return J;
}
int FileHandler::getC_WBus() {
    std::istringstream ss4(fileContents[3]);
    int J, C_WBus, C_MBus;
    ss4 >> J >> C_WBus >> C_MBus;
    return C_WBus;
}
int FileHandler::getC_MBus() {
    std::istringstream ss4(fileContents[3]);
    int J, C_WBus, C_MBus;
    ss4 >> J >> C_WBus >> C_MBus;
    return C_MBus;
}
int FileHandler::getMaxW() {
    std::istringstream ss5(fileContents[4]);
    int maxW, getOnOffTime;
    ss5 >> maxW >> getOnOffTime;
    return maxW;
}
int FileHandler::getGetOnOffTime() {
    std::istringstream ss5(fileContents[4]);
    int maxW, getOnOffTime;
    ss5 >> maxW >> getOnOffTime;
    return getOnOffTime;
}

// Assuming fileContents is a member of FileHandler and contains all lines of the file
Queue<std::vector<std::string>> FileHandler::processEventLines() {
    Queue<std::vector<std::string>> eventQueue;

    // Starting from the line where event lines begin
    for (size_t i = 6; i < fileContents.size(); ++i) {
        std::istringstream iss(fileContents[i]);
        std::vector<std::string> lineDetails;
        std::string word;

        while (iss >> word) {
            lineDetails.push_back(word);
        }

        // Check for SP Passenger and their statue
        if (lineDetails.size() > 1 && lineDetails[1] == "SP" && lineDetails.size() == 6) {
            // SP Passenger with statue provided
        } else if (lineDetails.size() > 1 && lineDetails[1] == "SP" && lineDetails.size() == 5) {
            // SP Passenger without statue, set statue to 'normal'
            lineDetails.push_back("normal");
        }

        eventQueue.enqueue(lineDetails);
    }

    return eventQueue;
}
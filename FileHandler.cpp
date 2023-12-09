
#include "FileHandler.h"

#include <utility>

FileHandler::FileHandler(std::string fileName) : fileName(std::move(fileName)) {
}

std::string FileHandler::getFileName() {
    return fileName;
}

int FileHandler::getBusData() {
    std::ifstream busFile;
    busFile.open(getFileName());
    if (!busFile.is_open()) {
        std::cout << "Error opening file" << std::endl;
        return 1;
    }
    std::string line;
    while (std::getline(busFile, line)) {
        std::cout << line << std::endl;
    }
    busFile.close();
    return 0;
}

Queue<std::string> FileHandler::getEventList() {
    std::ifstream eventFile;
    eventFile.open(getFileName());
    if (!eventFile.is_open()) {
        std::cout << "Error opening file" << std::endl;
        return {};
    }
    std::string line;
    Queue<std::string> eventList;
    while (std::getline(eventFile, line)) {
        eventList.enqueue(line);
    }
    eventFile.close();
    return eventList;
}

int FileHandler::getStationData() {
    std::ifstream stationFile;
    stationFile.open(getFileName());
    if (!stationFile.is_open()) {
        std::cout << "Error opening file" << std::endl;
        return 1;
    }
    std::string line;
    while (std::getline(stationFile, line)) {
        std::cout << line << std::endl;
    }
    stationFile.close();
    return 0;
}

int FileHandler::getCheckupData() {
    std::ifstream checkupFile;
    checkupFile.open(getFileName());
    if (!checkupFile.is_open()) {
        std::cout << "Error opening file" << std::endl;
        return 1;
    }
    std::string line;
    while (std::getline(checkupFile, line)) {
        std::cout << line << std::endl;
    }
    checkupFile.close();
    return 0;
}
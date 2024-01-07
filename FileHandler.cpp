#include "FileHandler.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include "Queue.h"

// Constructor that initializes the fileName and reads the file contents
FileHandler::FileHandler(std::string fileName) {
    this->fileName = std::move(fileName);
    readFileContents();
}
// Method to read the contents of the file and store them in the fileContents vector
void FileHandler::readFileContents() {
    std::ifstream file(fileName);
    std::string line;
    while (std::getline(file, line)) {
        fileContents.push_back(line);
    }
    file.close();
}

// Various getter methods to extract specific data from the file contents

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

int FileHandler::getNumEvents() {
    std::istringstream ss(fileContents[5]);
    int numEvents;
    ss >> numEvents;
    return numEvents;
}

// Method to write the data of finished passengers to the output file
void FileHandler::writeToFile(Queue<PassengerClass*>& passengers){

    std::ofstream outputFile("../FileOutput.txt");
    int NPCount, TotalPass, SPCount, WPCount = 0;
    TimeClass TotalTrip = 0, TotalWait = 0;
    std::vector<int> buses;
    if (outputFile.is_open()) {
        outputFile << "FT\t\tID\tAT\t\t\tWT\t\t\tTT\n";
        while (!passengers.isEmpty()) {
            PassengerClass* passenger = passengers.frontElement();
            outputFile << passenger->getLeaveTime() << "\t"
                    << passenger->getPassengerID() << "\t"
                    << passenger->getArrivalTime() << "\t\t"
                    << passenger->getOnTime() - passenger->getArrivalTime() << "\t\t"
                    << passenger->getLeaveTime() - passenger->getArrivalTime() << "\n";
            TotalTrip = TotalTrip + passenger->getLeaveTime() - passenger->getOnTime();
            TotalWait = TotalWait + passenger->getOnTime() - passenger->getArrivalTime();
            passengers.dequeue();

            if (passenger->getPassengerType() == "NP") {
                NPCount++;
                TotalPass++;
            } else if (passenger->getPassengerType() == "SP") {
                SPCount++;
                TotalPass++;
            } else {
                WPCount++;
                TotalPass++;
            }
        }
        outputFile << "Total Passengers : " << TotalPass << "\t [NP :" << NPCount << "\t SP :" << SPCount << "\t WP :"
                << WPCount << "]\n";
        outputFile << "Avg Waiting Time for Passengers : " << (TotalWait / TotalPass) << "\n";
        outputFile << "Avg Trip Time for Passengers : " << (TotalTrip / TotalPass) << "\n";
        outputFile << "Buses : " << this->getWBusCount() + this->getMBusCount() << "\t [MBus :" <<
                this->getMBusCount() << "\t WBus :" << this->getWBusCount() << "]\n";
        outputFile.close();
    } else {
        std::cout << "Unable to open file";
    }
}


// Method to process the event lines from the file and return them as a queue of vectors
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
            lineDetails.push_back("normal");
        } else if (lineDetails.size() > 1 && lineDetails[1] == "SP" && lineDetails.size() == 5) {
            // SP Passenger without statue, set statue to 'normal'
            lineDetails.push_back("normal");
        }

        eventQueue.enqueue(lineDetails);
    }

    return eventQueue;
}

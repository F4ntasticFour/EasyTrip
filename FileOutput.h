//
// Created by Marwan Amr on 07/01/2024.
//


#ifndef EASYTRIP_FILEOUTPUT_H
#define EASYTRIP_FILEOUTPUT_H

#include <fstream>
#include "Queue.h"
#include "PassengerClass.h"
#include "BusClass.h"
#include "FileHandler.h"



void writeToFile(Queue<PassengerClass *> passengers, FileHandler fileHandler) {
    std::ofstream outputFile("../FileOutput.txt");
    int NPCount,TotalPass,SPCount,WPCount = 0;
    TimeClass TotalTrip = 0, TotalWait = 0;
    std::vector<int> buses;
    if (outputFile.is_open()) {
        outputFile << "FT\t\tID\tAT\t\t\tWT\t\t\tTT\n";

        while (!passengers.isEmpty()) {
            PassengerClass* passenger = passengers.frontElement();
            outputFile << passenger->getLeaveTime()<< "\t"
                       << passenger->getPassengerID() << "\t"
                       << passenger->getArrivalTime() << "\t\t"
                       << passenger->getOnTime()-passenger->getArrivalTime() << "\t\t"
                       << passenger->getLeaveTime()-passenger->getArrivalTime() << "\n";
            TotalTrip =TotalTrip+ passenger->getLeaveTime()-passenger->getOnTime();
            TotalWait = TotalWait + passenger->getOnTime()-passenger->getArrivalTime();
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
        outputFile << "Total Passengers : " << TotalPass << "\t [NP :" << NPCount << "\t SP :" << SPCount << "\t WP :" << WPCount << "]\n";
        outputFile << "Avg Waiting Time for Passengers : " << (TotalWait / TotalPass)<< "\n";
        outputFile << "Avg Trip Time for Passengers : " << (TotalTrip / TotalPass) <<"\n";
        outputFile << "Buses : " << fileHandler.getWBusCount()+fileHandler.getMBusCount()<< "\t [MBus :" << fileHandler.getMBusCount() << "\t WBus :" << fileHandler.getWBusCount() << "]\n";


        outputFile.close();
    } else {
        std::cout << "Unable to open file";
    }
}


#endif //EASYTRIP_FILEOUTPUT_H
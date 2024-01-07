//
// Created by Marwan Amr on 07/01/2024.
//

#ifndef EASYTRIP_FILEOUTPUT_H
#define EASYTRIP_FILEOUTPUT_H

#include <fstream>

void writeToFile(Queue<PassengerClass>* passengers) {
    std::ofstream outputFile("FileOutput.txt");
    if (outputFile.is_open()) {
        outputFile << "FT\t\tID\tAT\t\tWT\t\tTT\n";

        while (!passengers->isEmpty()) {
            PassengerClass* passenger = passengers->frontElement();
            outputFile << passenger->getArrivalTime()<< "\t"
                       << passenger->getPassengerID() << "\t"
                       << passenger->getArrivalTime() << "\t\t"
                       << passenger->getLeaveTime() << "\t\t"
                       << passenger->getGetOnOffTime() << "\n";
        }

        outputFile.close();
    } else {
        std::cout << "Unable to open file";
    }
}

#endif //EASYTRIP_FILEOUTPUT_H

#include <iostream>
#include "PassengerClass.h"
#include "EventClass.h"
#include "StationClass.h"
#include "BusClass.h"
#include "FileHandler.h"
#include "UiClass.h"

using namespace std;

int main() {
    // Load configuration from a file
    FileHandler fileHandler("../random_file.txt"); // Adjust path as needed
    // Initialize the company with parameters from the file
    CompanyClass* company = new CompanyClass(fileHandler.getNumStations(),
                                             fileHandler.getTimeBetweenStations(),
                                             fileHandler.getWBusCount(),
                                             fileHandler.getMBusCount(),
                                             fileHandler.getWBusCapacity(),
                                             fileHandler.getMBusCapacity(),
                                             fileHandler.getJ(),
                                             fileHandler.getC_WBus(),
                                             fileHandler.getC_MBus());

    // Start simulation at 4:00
    TimeClass currentTime(4, 0);
    TimeClass endTime(22, 0);

    // Main simulation loop
    while (currentTime < endTime) {
        // Process events for the current time
        processEvent("../random_file.txt", currentTime, company);


        // Bus release logic
        if (currentTime.minutes % 15 == 0) {
            BusClass* bus = company->
            if (bus != nullptr) {
                int randomStation = rand() % company->getStationCount();
                company->moveBusToStation(bus, randomStation);
            }
        }

        // Bus operation logic
        for (int i = 0; i < company->getTotalBuses(); i++) {
            BusClass* bus = company->getBus(i);
            if (bus != nullptr) {
                // Move bus to next station
                int nextStation = (bus->getStationId() + 1) % company->getStationCount();
                company->moveBusToStation(bus, nextStation);

                // Offboard passengers
                bus->offboardPassengers(currentTime);

                // Onboard passengers
                bus->onboardPassengers(company->getStation(nextStation)->getWaitingPassengers());
            }
        }

        // Increment time by one minute
        currentTime.tick();
    }

    // Post-22:00 operations
    for (int i = 0; i < company->getTotalBuses(); i++) {
        BusClass* bus = company->getBus(i);
        if (bus != nullptr && bus->getPassengerCount() == 0) {
            // Move bus to station #0
            company->moveBusToStation(bus, 0);
        }
    }

    // Maintenance operations
    for (int i = 0; i < company->getTotalBuses(); i++) {
        BusClass* bus = company->getBus(i);
        if (bus != nullptr) {
            bus->performMaintenance();
        }
    }

    // Clean up resources
    delete company;

    return 0;
}
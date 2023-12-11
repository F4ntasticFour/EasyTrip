// CompanyClass.cpp

#include "CompanyClass.h"
#include<unistd.h>

#include "FileHandler.h"
#include "EventClass.h"

int microsecond = 1000000;

CompanyClass::CompanyClass(int StationCount, TimeClass TimeBetweenStations, int NumberOfWCBuses, int NumberOfMBuses,
                           int WCBusCapacity, int MBusCapacity, int TripsBeforeCheckup,
                           TimeClass CheckupDurationWCBus, TimeClass CheckupDurationMBus)
    : StationCount(StationCount),
      TimeBetweenStations(TimeBetweenStations),
      NumberOfWCBuses(NumberOfWCBuses),
      NumberOfMBuses(NumberOfMBuses),
      WCBusCapacity(WCBusCapacity),
      MBusCapacity(MBusCapacity),
      TripsBeforeCheckup(TripsBeforeCheckup),
      CheckupDurationWCBus(CheckupDurationWCBus),
      CheckupDurationMBus(CheckupDurationMBus) {
    StationList.resize(StationCount + 1);
    for (auto i = 0; i < StationCount; i++) {
        StationList[i] = Station(i);
    }
    for (int i = 0; i < NumberOfMBuses; ++i) {
        auto* bus = new BusClass(i, "Mbus", TimeBetweenStations, MBusCapacity,
                                 CheckupDurationMBus, TripsBeforeCheckup, 0);
        StationList[0].addFwBus(bus);
    }
    for (int i = 0; i < NumberOfWCBuses; ++i) {
        auto* bus = new BusClass(i, "Wbus", TimeBetweenStations, WCBusCapacity,
                                 CheckupDurationWCBus, TripsBeforeCheckup, 0);
        StationList[0].addFwBus(bus);
    }
}


bool CompanyClass::busAtCheckup(BusClass* Bus) {
    if (Bus->getBusCurrentStation() == 0 && Bus->getJourneyCompleted() == TripsBeforeCheckup) {
        BusCheckUpQueue.enqueue(Bus);
        return true;
    }
    return false;
}

void CompanyClass::moveBus() {
    std::wcerr << "called" << std::endl;
    for (int StationID = 0; StationID < StationCount + 1; StationID++) {
        if (StationID == 0) {
            Queue<BusClass *> tempFwQueue;
            while (!StationList[StationID].isFwBusEmpty()) {
                if (BusClass* bus = StationList[StationID].removeFwBus(); bus->getIsMoved() == false) {
                    bus->setIsMoved(true);
                    bus->setBusCurrentStation(bus->getBusCurrentStation() + 1);
                    bus->tickJourneyCompleted();
                    StationList[StationID + 1].addFwBus(bus);
                    bus->setBusDirection("Fw");
                    std::cout << "Bus " << bus->getBusID() << " moved to station " << bus->getBusCurrentStation() <<
                            std::endl;
                } else {
                    tempFwQueue.enqueue(bus);
                }
                while (!tempFwQueue.isEmpty()) {
                    StationList[StationID].addFwBus(tempFwQueue.frontElement());
                    tempFwQueue.dequeue();
                }
            }
        }
        else if (StationID == StationCount) {
            Queue<BusClass *> tempBwQueue;
            while (!StationList[StationID].isFwBusEmpty()) {
                BusClass* bus = StationList[StationID].removeFwBus();
                if (bus->getBusCurrentStation() == StationCount && bus->getIsMoved() == false && bus->
                    getBusDirection() == "Fw") {
                    bus->setIsMoved(true);
                    bus->setBusCurrentStation(bus->getBusCurrentStation() - 1);
                    bus->setBusDirection("Bw");
                    bus->tickJourneyCompleted();
                    StationList[StationID - 1].addBwBus(bus);
                    std::cout << "Bus " << bus->getBusID() << " moved to station " << bus->getBusCurrentStation() <<
                            std::endl;
                } else {
                    tempBwQueue.enqueue(bus);
                }
            }
            while (!tempBwQueue.isEmpty()) {
                StationList[StationID].addFwBus(tempBwQueue.frontElement());
                tempBwQueue.dequeue();
            }
        } else {
            Queue<BusClass *> tempFwQueue;
            while (!StationList[StationID].isFwBusEmpty()) {
                if (BusClass* bus = StationList[StationID].removeFwBus(); bus->getIsMoved() == false && bus->
                                                                          getBusDirection() == "Fw") {
                    bus->setIsMoved(true);
                    bus->setBusCurrentStation(bus->getBusCurrentStation() + 1);
                    bus->tickJourneyCompleted();
                    StationList[StationID + 1].addFwBus(bus);
                    std::cout << "Bus " << bus->getBusID() << " moved to station " << bus->getBusCurrentStation() <<
                            std::endl;
                } else {
                    tempFwQueue.enqueue(bus);
                }
            }
            while (!tempFwQueue.isEmpty()) {
                StationList[StationID].addFwBus(tempFwQueue.frontElement());
                tempFwQueue.dequeue();
            }
        }
        {
            while (!StationList[StationID].isBwBusEmpty()) {
                Queue<BusClass *> tempBwQueue;
                if (BusClass* bus = StationList[StationID].removeBwBus();
                    bus->getIsMoved() == false && bus->getBusDirection() == "Bw") {
                    if (bus->getBusCurrentStation() > 1) {
                        bus->setIsMoved(true);
                        bus->setBusCurrentStation(bus->getBusCurrentStation() - 1);
                        bus->tickJourneyCompleted();
                        StationList[StationID - 1].addBwBus(bus);
                        std::cout << "Bus " << bus->getBusID() << " moved to station " << bus->getBusCurrentStation() <<
                                std::endl;
                    }
                    else {
                        bus->setIsMoved(true);
                        bus->setBusCurrentStation(bus->getBusCurrentStation() + 1);
                        bus->setBusDirection("Fw");
                        bus->tickJourneyCompleted();
                        StationList[StationID + 1].addFwBus(bus);
                        std::cout << "Bus " << bus->getBusID() << " moved to station " << bus->getBusCurrentStation() <<
                                std::endl;
                    }
                } else {
                    tempBwQueue.enqueue(bus);
                }
                while (!tempBwQueue.isEmpty()) {
                    StationList[StationID].addFwBus(tempBwQueue.frontElement());
                    tempBwQueue.dequeue();
                }
            }
        }
    }

    for (int StationIndex = 0; StationIndex < StationCount+1; StationIndex++) {
        Queue<BusClass *> tempFwQueue;
        while (!StationList[StationIndex].isFwBusEmpty()) {
            BusClass* bus = StationList[StationIndex].removeFwBus();
            bus->setIsMoved(false);
            tempFwQueue.enqueue(bus);
        }
        while (!tempFwQueue.isEmpty()) {
            StationList[StationIndex].addFwBus(tempFwQueue.frontElement());
            tempFwQueue.dequeue();
        }
        Queue<BusClass *> tempBwQueue;
        while (!StationList[StationIndex].isBwBusEmpty()) {
            BusClass* bus = StationList[StationIndex].removeBwBus();
            bus->setIsMoved(false);
            tempBwQueue.enqueue(bus);
        }
        while (!tempBwQueue.isEmpty()) {
            StationList[StationIndex].addBwBus(tempBwQueue.frontElement());
            tempBwQueue.dequeue();
        }
    }
}


bool CompanyClass::addPassenger(PassengerClass* Passenger) {
    if (Passenger->getPassengerType() == "NP") {
        StationList[Passenger->getStartStation()].addNpPassenger(Passenger);
        return true;
    }
    if (Passenger->getPassengerType() == "SP") {
        StationList[Passenger->getStartStation()].addSpPassenger(Passenger);
        return true;
    }
    if (Passenger->getPassengerType() == "WP") {
        StationList[Passenger->getStartStation()].addWpPassenger(Passenger);
        return true;
    }
    return false;
}

int CompanyClass::getCount(int StationID, std::string PassengerType) {
    if (PassengerType == "NP") {
        return this->getStation(StationID).getCount(PassengerType);
    }
    if (PassengerType == "SP") {
        return this->getStation(StationID).getCount(PassengerType);
    }
    if (PassengerType == "WP") {
        return this->getStation(StationID).getCount(PassengerType);
    }
    return 0;
}

bool CompanyClass::addFinshedPassengers(PassengerClass* Passenger, BusClass* Bus) {
    if (Bus->getBusCurrentStation() == Passenger->getEndStation()) {
        FinishedPassengers.enqueue(Passenger);
        StationList[Passenger->getEndStation()].removeNpPassenger(Passenger);
        return true;
    }
    return false;
}

bool CompanyClass::leavePassenger(PassengerClass* Passenger) {
    if (Passenger->getEndStation() == Passenger->getStartStation()) {
        if (Passenger->getPassengerType() == "NP") {
            FinishedPassengers.enqueue(Passenger);
            StationList[Passenger->getStartStation()].removeNpPassenger(Passenger);
        } else if (Passenger->getPassengerType() == "SP") {
            FinishedPassengers.enqueue(Passenger);
            StationList[Passenger->getStartStation()].removeSpPassenger();
        } else if (Passenger->getPassengerType() == "WP") {
            FinishedPassengers.enqueue(Passenger);
            StationList[Passenger->getStartStation()].removeWpPassenger();
        }
        return true;
    }
    return false;
}

PassengerClass * CompanyClass::getPassengerByID(int ID) {
    for (int i = 0; i < StationCount; ++i) {
        if ( StationList[i].getNpPassengerByID(ID)!= nullptr) {
            return StationList[i].getNpPassengerByID(ID);
        }
    }
    return new PassengerClass();
}

BusClass* CompanyClass::getBus() {
    BusClass* bus = MovingBus.frontElement();
    MovingBus.dequeue();
    MovingBus.enqueue(bus);
    return bus;
}

int CompanyClass::getStationCount() const {
    return StationCount;
}

Queue<PassengerClass *> CompanyClass::getFinishedPassengers() {
    return FinishedPassengers;
}

Station CompanyClass::getStation(int StationID) {
    return StationList[StationID];
}


void CompanyClass::startSimulation(std::string filename) {
    FileHandler fileHandler(std::move(filename));
    auto* company = new CompanyClass(fileHandler.getNumStations(),
                                     TimeClass(0, fileHandler.getTimeBetweenStations()),
                                     fileHandler.getWBusCount(), fileHandler.getMBusCount(),
                                     fileHandler.getWBusCapacity(), fileHandler.getMBusCapacity(),
                                     fileHandler.getJ(), fileHandler.getC_WBus(), fileHandler.getC_MBus());
    TimeClass time(4, 0);

    Queue<std::vector<std::string>> eventQueue = fileHandler.processEventLines();

    EventManager eventManager(company, eventQueue);

    int timecounter = 0;

    while (time != TimeClass(7, 40)) {
        time.tick();
        usleep(0.1 * microsecond);
        std::cout << time << std::endl;
        eventManager.processEvents(time);

        while (timecounter == fileHandler.getTimeBetweenStations()) {
            company->moveBus();
            timecounter = 0;
        }
        timecounter++;
    }
    std::cout << "Station 0: NP: " << company->getStation(0).getCount("NP") << " Sp: " << company->getStation(0).
            getCount("SP") << " WP: " << company->getStation(0).getCount("WP") << std::endl;

    std::cout << "Station 1: NP: " << company->getStation(1).getCount("NP") << " Sp: " << company->getStation(1).
            getCount("SP") << " WP: " << company->getStation(1).getCount("WP") << std::endl;

    std::cout << "Station 2: NP: " << company->getStation(2).getCount("NP") << " Sp: " << company->getStation(2).
            getCount("SP") << " WP: " << company->getStation(2).getCount("WP") << std::endl;

    std::cout << "Station 3: NP: " << company->getStation(3).getCount("NP") << " Sp: " << company->getStation(3).
            getCount("SP") << " WP: " << company->getStation(3).getCount("WP") << std::endl;

    std::cout << "Station 4: NP: " << company->getStation(4).getCount("NP") << " Sp: " << company->getStation(4).
            getCount("SP") << " WP: " << company->getStation(4).getCount("WP") << std::endl;
}

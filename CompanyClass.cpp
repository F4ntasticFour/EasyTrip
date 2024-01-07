// CompanyClass.cpp

#include "CompanyClass.h"
#include<unistd.h>
#include "FileHandler.h"
#include "EventClass.h"

int microsecond = 1000000;

// Constructor for the CompanyClas
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
        auto* bus = new BusClass(1000 + i, "Mbus", TimeBetweenStations, MBusCapacity,
                                 CheckupDurationMBus, TripsBeforeCheckup, 0);
        StationList[0].addFwBus(bus);
    }
    for (int i = 0; i < NumberOfWCBuses; ++i) {
        auto* bus = new BusClass(2000 + i, "Wbus", TimeBetweenStations, WCBusCapacity,
                                 CheckupDurationWCBus, TripsBeforeCheckup, 0);
        StationList[0].addFwBus(bus);
    }
}

// Method to check if a bus is at checkup
bool CompanyClass::busAtCheckup(BusClass* Bus) {
    if (Bus->getBusCurrentStation() == 0 && Bus->getJourneyCompleted() == TripsBeforeCheckup) {
        BusCheckUpQueue.enqueue(Bus);
        return true;
    }
    return false;
}
// Method to move the bus
void CompanyClass::moveBus() {
    for (int StationID = 0; StationID < StationCount + 1; StationID++) {
        if (StationID == 0) {
            Queue<BusClass *> tempFwQueue;
            if (!StationList[StationID].isFwBusEmpty()) {
                if (BusClass* bus = StationList[StationID].removeFwBus(); bus->getIsMoved() == false) {
                    bus->setIsMoved(true);
                    bus->setBusCurrentStation(bus->getBusCurrentStation() + 1);
                    StationList[StationID + 1].addFwBus(bus);
                    bus->setBusDirection("Fw");
                    std::cout << "Bus " << bus->getBusID() << " moved to station " << bus->getBusCurrentStation() <<
                            std::endl;
                }else {
                    tempFwQueue.enqueue(bus);
                }
                while (!tempFwQueue.isEmpty()) {
                    StationList[StationID].addFwBus(tempFwQueue.frontElement());
                    tempFwQueue.dequeue();
                }
            }
        } else if (StationID == StationCount) {
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
                    StationList[StationID + 1].addFwBus(bus);
                    std::cout << "Bus " << bus->getBusID() << " moved to station " << bus->getBusCurrentStation() <<
                            std::endl;
                }
                else if (bus->getJourneyCompleted() >= TripsBeforeCheckup) {
                    BusCheckUpQueue.enqueue(bus);
                }
                else {
                    tempFwQueue.enqueue(bus);
                }
            }
            while (!tempFwQueue.isEmpty()) {
                StationList[StationID].addFwBus(tempFwQueue.frontElement());
                tempFwQueue.dequeue();
            }
        } {
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
                    } else {
                        bus->setIsMoved(true);
                        bus->setBusCurrentStation(bus->getBusCurrentStation() + 1);
                        bus->setBusDirection("Fw");
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

    for (int StationIndex = 0; StationIndex < StationCount + 1; StationIndex++) {
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

// Method to add a passenger
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
// Method to get the count of passengers
int CompanyClass::getCount(int StationID, const std::string& PassengerType) {
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

// Method to add finished passengers
bool CompanyClass::ADDFinishedpassengers(PassengerClass* Passenger) {
    FinishedPassengers.enqueue(Passenger);
    return true;
};
// Method to add finished passengers
bool CompanyClass::addFinshedPassengers(PassengerClass* Passenger, BusClass* Bus) {
    if (Bus->getBusCurrentStation() == Passenger->getEndStation()) {
        FinishedPassengers.enqueue(Passenger);
        StationList[Passenger->getEndStation()].leaveNpPassenger(Passenger);
        return true;
    }
    return false;
}
// Method to leave a passenger
bool CompanyClass::leavePassenger(PassengerClass* Passenger) {
    if (Passenger->getEndStation() == Passenger->getStartStation()) {
        if (Passenger->getPassengerType() == "NP") {
            FinishedPassengers.enqueue(Passenger);
            StationList[Passenger->getStartStation()].leaveNpPassenger(Passenger);
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
// Method to get a passenger by ID /
PassengerClass* CompanyClass::getPassengerByID(int ID) {
    for (int i = 0; i < StationCount; ++i) {
        if (StationList[i].getNpPassengerByID(ID) != nullptr) {
            return StationList[i].getNpPassengerByID(ID);
        }
    }
    return new PassengerClass();
}
// Method to get a bus
BusClass* CompanyClass::getBus() {
    BusClass* bus = MovingBus.frontElement();
    MovingBus.dequeue();
    MovingBus.enqueue(bus);
    return bus;
}
// Method to get the station count
int CompanyClass::getStationCount() const {
    return StationCount;
}
// Method to get the finished passengers
Queue<PassengerClass *> CompanyClass::getFinishedPassengers() {
    return FinishedPassengers;
}
// Method to get a station
Station CompanyClass::getStation(int StationID) {
    return StationList[StationID];
}
// Method to onboard passengers
void CompanyClass::onBoardPassengers(TimeClass& Time) {
    for (int StationIndex = 0; StationIndex < StationCount + 1; StationIndex++) {
        Queue<BusClass *> tempFwQueue;
        Queue<PassengerClass *> tempPassengerFwQueue;
        while (!StationList[StationIndex].isFwBusEmpty()) {
            BusClass* bus = StationList[StationIndex].removeFwBus();
            while (!StationList[StationIndex].getSPpassengers().isEmpty()) {
                PassengerClass* passenger = StationList[StationIndex].removeSpPassenger();
                if (passenger->getPassengerDirection() == "Fw") {
                    passenger->setGetOnTime(Time);
                    bus->onBoardPassenger(passenger);
                    std::cout << "SP Passenger on boarded Bus: " << bus->getBusID() << std::endl;
                } else {
                    tempPassengerFwQueue.enqueue(passenger);
                }
            }
            while (!StationList[StationIndex].getNPpassengers().isEmpty()) {
                PassengerClass* passenger = StationList[StationIndex].removeNpPassenger();
                if (passenger->getPassengerDirection() == "Fw") {
                    passenger->setGetOnTime(Time);
                    if (passenger->getOnTime() - passenger->getArrivalTime() > TimeClass(0, 30)) {
                        passenger->promotePassenger();
                    }
                    bus->onBoardPassenger(passenger);
                    std::cout << "NP Passenger on boarded Bus: " << bus->getBusID() << std::endl;
                } else {
                    tempPassengerFwQueue.enqueue(passenger);
                }
            }
            while (!StationList[StationIndex].getWPpassengers().isEmpty()) {
                PassengerClass* passenger = StationList[StationIndex].removeWpPassenger();
                if (passenger->getPassengerDirection() == "Fw") {
                    passenger->setGetOnTime(Time);
                    bus->onBoardPassenger(passenger);
                    std::cout << "WP Passenger on boarded Bus: " << bus->getBusID() << std::endl;
                } else {
                    tempPassengerFwQueue.enqueue(passenger);
                }
            }
            tempFwQueue.enqueue(bus);
        }
        while (!tempFwQueue.isEmpty()) {
            StationList[StationIndex].addFwBus(tempFwQueue.frontElement());
            tempFwQueue.dequeue();
        }
        while (!tempPassengerFwQueue.isEmpty()) {
            PassengerClass* Passenger = tempPassengerFwQueue.frontElement();
            StationList[Passenger->getStartStation()].addPassenger(Passenger);
            tempPassengerFwQueue.dequeue();
        }
        Queue<BusClass *> tempBwQueue;
        Queue<PassengerClass *> tempPassengerBwQueue;
        while (!StationList[StationIndex].isBwBusEmpty()) {
            BusClass* bus = StationList[StationIndex].removeBwBus();
            while (!StationList[StationIndex].getSPpassengers().isEmpty()) {
                PassengerClass* passenger = StationList[StationIndex].removeSpPassenger();
                if (passenger->getPassengerDirection() == "Bw") {
                    passenger->setGetOnTime(Time);
                    bus->onBoardPassenger(passenger);
                    std::cout << "SP Passenger  boarded Bus: " << bus->getBusID() << std::endl;
                } else {
                    tempPassengerBwQueue.enqueue(passenger);
                }
            }
            while (!StationList[StationIndex].getNPpassengers().isEmpty()) {
                PassengerClass* passenger = StationList[StationIndex].removeNpPassenger();
                if (passenger->getPassengerDirection() == "Bw") {
                    passenger->setGetOnTime(Time);
                    if (passenger->getOnTime() - passenger->getArrivalTime() > TimeClass(0, 30)) {
                        passenger->promotePassenger();
                    }
                    bus->onBoardPassenger(passenger);
                    std::cout << "NP Passenger on boarded Bus: " << bus->getBusID() << std::endl;
                } else {
                    tempPassengerBwQueue.enqueue(passenger);
                }
            }
            while (!StationList[StationIndex].getWPpassengers().isEmpty()) {
                PassengerClass* passenger = StationList[StationIndex].removeWpPassenger();
                if (passenger->getPassengerDirection() == "Bw") {
                    passenger->setGetOnTime(Time);
                    bus->onBoardPassenger(passenger);
                    std::cout << "WP Passenger on boarded Bus: " << bus->getBusID() << std::endl;
                } else {
                    tempPassengerBwQueue.enqueue(passenger);
                }
            }
            tempBwQueue.enqueue(bus);
        }
        while (!tempBwQueue.isEmpty()) {
            StationList[StationIndex].addBwBus(tempBwQueue.frontElement());
            tempBwQueue.dequeue();
        }
        while (!tempPassengerBwQueue.isEmpty()) {
            PassengerClass* Passenger = tempPassengerBwQueue.frontElement();
            StationList[Passenger->getStartStation()].addPassenger(
                Passenger);
            tempPassengerBwQueue.dequeue();
        }
    }
}
// Method to offboard passengers
void CompanyClass::offBoardPassengers(TimeClass& Time) {
    for (int StationIndex = 0; StationIndex < StationCount + 1; StationIndex++) {
        Queue<BusClass *> tempFwQueue;
        while (!StationList[StationIndex].isFwBusEmpty()) {
            BusClass* bus = StationList[StationIndex].removeFwBus();
            bus->offBoardPassenger(this, Time);
            tempFwQueue.enqueue(bus);
        }
        while (!tempFwQueue.isEmpty()) {
            StationList[StationIndex].addFwBus(tempFwQueue.frontElement());
            tempFwQueue.dequeue();
        }
        Queue<BusClass *> tempBwQueue;
        while (!StationList[StationIndex].isBwBusEmpty()) {
            BusClass* bus = StationList[StationIndex].removeBwBus();
            bus->offBoardPassenger(this, Time);
            tempBwQueue.enqueue(bus);
        }
        while (!tempBwQueue.isEmpty()) {
            StationList[StationIndex].addBwBus(tempBwQueue.frontElement());
            tempBwQueue.dequeue();
        }
    }
}

void CompanyClass::tickCheckup() {
    while (!BusCheckUpQueue.isEmpty()) {
        BusClass* bus = BusCheckUpQueue.frontElement();
        BusCheckUpQueue.dequeue();
        bus->clearJourneyCompleted();
        std::cerr << "Bus " << bus->getBusID() << " is at checkup" << std::endl;
        StationList[0].addFwBus(bus);
    }
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
    int timecountercheckup = 0;

    while (time != TimeClass(13, 0)) {
        time.tick();
        std::cout << time << std::endl;
        eventManager.processEvents(time);
        usleep(0.1 * microsecond);

        while (timecounter == fileHandler.getTimeBetweenStations()) {
            company->offBoardPassengers(time);
            usleep(0.1 * microsecond);
            company->onBoardPassengers(time);
            usleep(0.1 * microsecond);
            company->moveBus();
            timecounter = 0;
        }
        while (timecountercheckup == fileHandler.getC_MBus()) {
            company->tickCheckup();
            timecountercheckup = 0;
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
    std::cout << "Station 5: NP: " << company->getStation(5).getCount("NP") << " Sp: " << company->getStation(5).
            getCount("SP") << " WP: " << company->getStation(5).getCount("WP") << std::endl;
    std::cout << "Station 6: NP: " << company->getStation(6).getCount("NP") << " Sp: " << company->getStation(6).
            getCount("SP") << " WP: " << company->getStation(6).getCount("WP") << std::endl;
    std::cout << "Station 7: NP: " << company->getStation(7).getCount("NP") << " Sp: " << company->getStation(7).
            getCount("SP") << " WP: " << company->getStation(7).getCount("WP") << std::endl;
    std::cout << "Station 8: NP: " << company->getStation(8).getCount("NP") << " Sp: " << company->getStation(8).
            getCount("SP") << " WP: " << company->getStation(8).getCount("WP") << std::endl;
    std::cout << "Station 9: NP: " << company->getStation(9).getCount("NP") << " Sp: " << company->getStation(9).
            getCount("SP") << " WP: " << company->getStation(9).getCount("WP") << std::endl;


    Queue<PassengerClass *> FinishedPassengers = company->getFinishedPassengers();
    fileHandler.writeToFile(FinishedPassengers);
}

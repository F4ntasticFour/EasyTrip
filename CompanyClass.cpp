// CompanyClass.cpp

#include "CompanyClass.h"

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
    StationList.resize(StationCount);
    for (auto i = 0; i < StationCount; i++) {
        StationList[i] = Station(i);
    }
    for (int i = 0; i < NumberOfMBuses; ++i) {
        auto* bus = new BusClass(i, "Mbus", TimeBetweenStations, MBusCapacity,
                                 CheckupDurationMBus, TripsBeforeCheckup);
        StationList[0].addFwBus(bus);
    }
    for (int i = 0; i < NumberOfWCBuses; ++i) {
        auto* bus = new BusClass(i, "Wbus", TimeBetweenStations, WCBusCapacity,
                                 CheckupDurationWCBus, TripsBeforeCheckup);
        StationList[0].addFwBus(bus);
    }
}

bool CompanyClass::busMoving(BusClass* Bus) {
    MovingBus.enqueue(Bus);
    return true;
}

bool CompanyClass::busAtCheckup(BusClass* Bus) {
    if (Bus->getBusCurrentStation() == 0 && Bus->getJourneyCompleted() == TripsBeforeCheckup) {
        BusCheckUpQueue.enqueue(Bus);
        return true;
    }
    return false;
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
    } else if (PassengerType == "SP") {
        return this->getStation(StationID).getCount(PassengerType);
    } else if (PassengerType == "WP") {
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

PassengerClass* CompanyClass::getPassengerByID(int ID) {
    for (int i = 0; i < StationCount; ++i) {
        if (StationList[i].getNpPassengerByID(ID) != nullptr) {
            return StationList[i].getNpPassengerByID(ID);
        }
    }
    return nullptr;
}

int CompanyClass::getStationCount() const {
    return StationCount;
}

Station CompanyClass::getStation(int StationID) {
    return StationList[StationID];
}

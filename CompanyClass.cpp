// CompanyClass.cpp

#include "CompanyClass.h"

CompanyClass::CompanyClass(int StationCount, TimeClass TimeBetweenStations, int NumberOfWCBuses, int NumberOfMBuses,
                           int WCBusCapacity, int MBusCapacity, int TripsBeforeCheckup, TimeClass CheckupDurationWCBus,
                           TimeClass CheckupDurationMBus) {
    this->StationCount = StationCount;
    for (auto i = 0; i < StationCount; i++) {
        StationList[i] = Station(i);
    };
    this->TimeBetweenStations = TimeBetweenStations;
    this->NumberOfWCBuses = NumberOfWCBuses;
    this->NumberOfMBuses = NumberOfMBuses;
    this->WCBusCapacity = WCBusCapacity;
    this->MBusCapacity = MBusCapacity;
    this->TripsBeforeCheckup = TripsBeforeCheckup;
    this->CheckupDurationWCBus = CheckupDurationWCBus;
    this->CheckupDurationMBus = CheckupDurationMBus;
    for (int i = 0; i < NumberOfMBuses; ++i) {
        BusClass* bus = new BusClass(i, "Mbus", TimeBetweenStations, MBusCapacity,
                                     CheckupDurationMBus, TripsBeforeCheckup);
        StationList[0].addFwBus(bus);
    }
    for (int i = 0; i < NumberOfWCBuses; ++i) {
        BusClass* bus = new BusClass(i, "Wbus", TimeBetweenStations, WCBusCapacity,
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
    StationList[Passenger->getStartStation()].addNpPassenger(Passenger);
    return true;
}

bool CompanyClass::addFinshedPassengers(PassengerClass* Passenger, BusClass* Bus) {
    if (Bus->getBusCurrentStation() == Passenger->getEndStation()) {
        FinishedPassengers.enqueue(Passenger);
        StationList[Passenger->getEndStation()].removeNpPassenger(Passenger);
        return true;
    }
    return false;
}
bool CompanyClass::leavePassenger(PassengerClass* Passenger,TimeClass LeaveTime) {
    if (Passenger->getEndStation() == Passenger->getStartStation()) {
        Passenger->setLeaveTime(LeaveTime);
        StationList[Passenger->getStartStation()].removeNpPassenger(Passenger);
        FinishedPassengers.enqueue(Passenger);
        return true;
    }
    return false;
}

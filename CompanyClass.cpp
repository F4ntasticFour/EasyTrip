// CompanyClass.cpp

#include "CompanyClass.h"


bool CompanyClass::busMoving(BusClass* Bus) {
    MovingBus.enqueue(Bus);
    return true;
}

bool CompanyClass::busAtCheckup(BusClass* Bus) {
    if (Bus->getBusCurrentStation() == 0 && Bus->getJourneyCompleted() == 5) {
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

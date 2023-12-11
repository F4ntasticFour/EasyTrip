#include "BusClass.h"

#include "CompanyClass.h"

BusClass::BusClass(int BusID, const std::string& busType, TimeClass TimeBetweenStations, int busCapacity,
                   TimeClass checkUpTime, int TripsBeforeCheckUp)


    : BusID(BusID), BusType(busType), TimeBetweenStations(TimeBetweenStations), BusCapacity(busCapacity),
      CheckUpTime(checkUpTime), BusCurrentStation(0), TripsBeforeCheckUp(TripsBeforeCheckUp) {
}

// Getters
std::string BusClass::getBusType() const {
    return BusType;
}

int BusClass::getBusCapacity() const {
    return BusCapacity;
}

int BusClass::getJourneyCompleted() const {
    return JourneyCompleted;
}

int BusClass::getBusCurrentStation() const {
    return BusCurrentStation;
}

std::string BusClass::getBusDirection() const {
    return BusDirection;
}

TimeClass BusClass::getCheckUpTime() const {
    return CheckUpTime;
}

int BusClass::getBusID(){
    return BusID;
}

// Setters
void BusClass::setBusType(const std::string& busType) {
    BusType = busType;
}

void BusClass::setBusCapacity(int busCapacity) {
    BusCapacity = busCapacity;
}

void BusClass::setJourneyCompleted(int journeyCompleted) {
    JourneyCompleted = journeyCompleted;
}

void BusClass::setCheckUpTime(TimeClass checkUpTime) {
    CheckUpTime = checkUpTime;
}

void BusClass::setBusCurrentStation(int busCurrentStation) {
    BusCurrentStation = busCurrentStation;
}


void BusClass::performMaintenance() {
}

bool BusClass::isSuitableForPassengerType(const std::string& passengerType) const {
    if (BusType == "WBus" && passengerType == "WP") {
        return true;
    } else if (BusType == "MBus" && (passengerType == "SP" || passengerType == "NP")) {
        return true;
    } else {
        return false;
    }
}

bool BusClass::onBoardPassenger(PassengerClass* Passenger) {
    if (PassengersOnBoard.size() < BusCapacity) {
        PassengersOnBoard.enqueue(Passenger, Passenger->getPriority());
        return true;
    }
    return false;
}

bool BusClass::offBoardPassenger(PassengerClass* Passenger, CompanyClass* Company) {
    if (PassengersOnBoard.frontElement() == Passenger && BusCurrentStation == Passenger
        ->getEndStation()) {
        Company->addFinshedPassengers(Passenger, this);
        PassengersOnBoard.dequeue();
        return true;
    }
    return false;
}

bool BusClass::moveToNextStation(CompanyClass* Company, TimeClass& CurrentTime) {

    if (BusCurrentStation == Company->getStationCount() - 1&& BusDirection == "Fw")  {
        BusCurrentStation--;
        Company->getStation(BusCurrentStation).addBwBus(this);
        BusDirection = "Bw";
        JourneyCompleted++;
        return true;
    }else if(BusDirection== "Bw" && BusCurrentStation == 0) {
        BusCurrentStation++;
        Company->getStation(BusCurrentStation).addFwBus(this);
        BusDirection = "Fw";
        JourneyCompleted++;
        return true;
    }
    else if (BusDirection == "Bw") {
        BusCurrentStation--;
        Company->getStation(BusCurrentStation).addBwBus(this);
        return true;
    }
    else if (BusDirection == "Fw") {
        BusCurrentStation++;
        Company->getStation(BusCurrentStation).addFwBus(this);
        return true;

    }
     return false;
}

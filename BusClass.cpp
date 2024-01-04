#include "BusClass.h"

#include "CompanyClass.h"

BusClass::BusClass(int BusID, const std::string& busType, TimeClass TimeBetweenStations, int busCapacity,
                   TimeClass checkUpTime, int TripsBeforeCheckUp, int BusCurrentStation)


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

int BusClass::getBusCurrentStation() {
    return BusCurrentStation;
}

int BusClass::getBusID() const {
    return BusID;
}

TimeClass BusClass::getCheckUpTime() const {
    return CheckUpTime;
}

bool BusClass::getIsMoved() {
    return isMoved;
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

void BusClass::setBusCurrentStation(int BusCurrentStation) {
    BusClass::BusCurrentStation = BusCurrentStation;
}

bool BusClass::setIsMoved(bool Moved) {
    isMoved = Moved;
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

bool BusClass::onBoardPassenger(CompanyClass* Company) {
    int index = Company->getStation(BusCurrentStation).getCount("NP");
    while (PassengersOnBoard.size() <= BusCapacity && Company->getStation(BusCurrentStation).getCount("NP") > 0) {
        PassengerClass* Passenger = Company->getStation(BusCurrentStation).getNpPassenger(index);
        PassengersOnBoard.enqueue(Passenger, Passenger->getEndStation());
        std::cout << "Passenger " << Passenger->getPassengerID() << " boarded bus " << BusID << std::endl;
        index = index - 1;
        return true;
    }
    return false;
}

bool BusClass::offBoardPassenger(CompanyClass* Company) {
    int i = PassengersOnBoard.size();
    while (i != 0) {
        if (PassengersOnBoard.frontElement()->getEndStation() == BusCurrentStation) {
            Company->addFinshedPassengers(PassengersOnBoard.frontElement(), this);
            PassengersOnBoard.dequeue();
        } else {
            auto* temp = PassengersOnBoard.frontElement();
            PassengersOnBoard.dequeue();
            PassengersOnBoard.enqueue(temp, temp->getPriority());
        }
        i--;
    }
    return true;
}

int BusClass::getOnBoardPassengerCount() {
    return PassengersOnBoard.size();
}

bool BusClass::offBoardAllPassenger(CompanyClass* Company) {
    while (PassengersOnBoard.size() > 0) {
        Company->addFinshedPassengers(PassengersOnBoard.frontElement(), this);
        PassengersOnBoard.dequeue();
    }
    return true;
}

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

std::string BusClass::getBusDirection() {
    return busDirection;
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

void BusClass::setBusDirection(std::string Direction) {
    busDirection = Direction;
}

void BusClass::tickJourneyCompleted() {
    JourneyCompleted++;
}

void BusClass::clearJourneyCompleted() {
    JourneyCompleted = 0;
}

void BusClass::performMaintenance() {
    JourneyCompleted = 0;

}

bool BusClass::onBoardPassenger(PassengerClass* Passenger) {
    if (getOnBoardPassengerCount() < BusCapacity) {
        if (BusType == "Wbus" && Passenger->getPassengerType() == "WP") {
            PassengersOnBoard.enqueue(Passenger);
            return true;
        }
        if (BusType == "Mbus" && (Passenger->getPassengerType() == "SP" || Passenger->getPassengerType() == "NP")) {
            PassengersOnBoard.enqueue(Passenger);
            return true;
        }
        return false;
    }
    return false;
}

void BusClass::offBoardPassenger(CompanyClass* Company, TimeClass& time) {
    Queue<PassengerClass *> tempQueue;
    while (!PassengersOnBoard.isEmpty()) {
        PassengerClass* currentPassenger = PassengersOnBoard.frontElement();
        PassengersOnBoard.dequeue();
        if (currentPassenger->getEndStation() == BusCurrentStation) {
            currentPassenger->setLeaveTime(time);
            Company->ADDFinishedpassengers(currentPassenger);
            std::cerr<<"Passenger "<< currentPassenger->getPassengerID()<<" got off at station "<<BusCurrentStation<<std::endl;
        } else {
            tempQueue.enqueue(currentPassenger);
        }
    }
    while (!tempQueue.isEmpty()) {
        PassengerClass* Passenger = tempQueue.frontElement();
        PassengersOnBoard.enqueue(Passenger);
        tempQueue.dequeue();
    }
}

int BusClass::getOnBoardPassengerCount() {
    return PassengersOnBoard.getLength();
}

bool BusClass::offBoardAllPassenger(CompanyClass* Company) {
    while (getOnBoardPassengerCount() > 0) {
        Company->addFinshedPassengers(PassengersOnBoard.frontElement(), this);
        PassengersOnBoard.dequeue();
    }
    return true;
}

#include "BusClass.h"
BusClass::BusClass(const std::string& busType, int busCapacity, int journeyCompleted, Time checkUpTime, int busCurrentStation)
        : BusType(busType), BusCapacity(busCapacity), JourneyCompleted(journeyCompleted), CheckUpTime(checkUpTime) {

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

Time BusClass::getCheckUpTime() const {
    return CheckUpTime;
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

void BusClass::setCheckUpTime(Time checkUpTime) {
    CheckUpTime = checkUpTime;
}



void BusClass::performMaintenance() {}

bool BusClass::isSuitableForPassengerType(const std::string& passengerType) const {
    if (BusType == "WBus" && passengerType == "WP") {
        return true;
    } else if (BusType == "MBus" && (passengerType == "SP" || passengerType == "NP")) {
        return true;
    } else {
        return false;
    }
}
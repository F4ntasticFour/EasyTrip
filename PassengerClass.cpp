#include "PassengerClass.h"

PassengerClass::PassengerClass() {}
PassengerClass::PassengerClass(Time &ArrivalTime, const int &StartStation, int &EndStation, Time &GetOnOffTime,
                               const std::string &passengerType)
        : ArrivalTime(ArrivalTime), StartStation(StartStation), EndStation(EndStation), GetOnOffTime(GetOnOffTime),
          PassengerType(passengerType) {
}


Time PassengerClass::getArrivalTime() const {
    return ArrivalTime;
}

int PassengerClass::getStartStation() const {
    return StartStation;
}

int PassengerClass::getEndStation() const {
    return EndStation;
}

Time PassengerClass::getGetOnOffTime() const {
    return GetOnOffTime;
}

std::string PassengerClass::getPassengerType() const {
    return PassengerType;
}

int PassengerClass::getPassengerID() const {
    return passengerID;
}
// Setters
void PassengerClass::setArrivalTime(const Time &arrivalTime) {
    ArrivalTime = arrivalTime;
}

void PassengerClass::setStartStation(const int &startStation) {
    StartStation = startStation;
}

void PassengerClass::setEndStation(const int &endStation) {
    EndStation = endStation;
}

void PassengerClass::setGetOnOffTime(Time getOnOffTime) {
    GetOnOffTime = getOnOffTime;
}

void PassengerClass::setPassengerType(const std::string &passengerType) {
    PassengerType = passengerType;
}

void PassengerClass::setStatue(const std::string &statue) {
    this->statue = statue;
}
void PassengerClass::setPassengerID(int passengerID) {
    this->passengerID = passengerID;
}

std::string PassengerClass::getStatue() const {
    return statue;
}



int PassengerClass::getPriority() const {
    if (getPassengerType() == "SP") {
        if (getStatue() == "Aged") {
            return 4;
        } else if (getStatue() == "POD") {
            return 3;
        } else if (getStatue() == "Pregnant") {
            return 2;
        }
    }
    return 1;
}

bool PassengerClass::operator==(const PassengerClass &rhs) const {
    return getPriority() == rhs.getPriority();
}

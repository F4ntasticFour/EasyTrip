#include "PassengerClass.h"

PassengerClass::PassengerClass() {
}

PassengerClass::PassengerClass(TimeClass ArrivalTime ,const int StartStation, int EndStation, int PassengerID,
                               const std::string& passengerType, const std::string& statue)
    :  StartStation(StartStation), EndStation(EndStation), PassengerID(PassengerID),
      PassengerType(passengerType), statue(statue) {
}

// Getters
TimeClass PassengerClass::getArrivalTime() {
    return ArrivalTime;
}

TimeClass PassengerClass::getLeaveTime() {
    return LeaveTime;
}
int PassengerClass::getStartStation() const {
    return StartStation;
}

int PassengerClass::getEndStation() const {
    return EndStation;
}

TimeClass PassengerClass::getGetOnOffTime() const {
    return GetOnOffTime;
}

std::string PassengerClass::getPassengerType() const {
    return PassengerType;
}

int PassengerClass::getPassengerID() const {
    return PassengerID;
}

// Setters
void PassengerClass::setArrivalTime(TimeClass ArrivalTime) {
    this->ArrivalTime = ArrivalTime;
}

void PassengerClass::setLeaveTime(TimeClass LeaveTime) {
    this->LeaveTime = LeaveTime;
}


void PassengerClass::setStartStation(int startStation) {
    StartStation = startStation;
}

void PassengerClass::setEndStation(int endStation) {
    EndStation = endStation;
}

void PassengerClass::setPassengerType(const std::string& passengerType) {
    PassengerType = passengerType;
}

void PassengerClass::setStatue(const std::string& statue) {
    this->statue = statue;
}

void PassengerClass::setPassengerID(int PassengerID) {
    this->PassengerID = PassengerID;
}

std::string PassengerClass::getStatue() const {
    return statue;
}


int PassengerClass::getPriority() const {
    if (getPassengerType() == "SP") {
        if (getStatue() == "Aged") {
            return 3;
        } else if (getStatue() == "POD") {
            return 2;
        } else if (getStatue() == "Pregnant") {
            return 1;
        }
    }
    return 4;
}

bool PassengerClass::operator==(const PassengerClass& rhs) const {
    return getPriority() == rhs.getPriority();
}
std::ostream& PassengerClass::operator<<(std::ostream& os) const {
    os << "ArrivalTime: " << ArrivalTime << " LeaveTime: " << LeaveTime << " StartStation: " << StartStation
       << " EndStation: " << EndStation << " PassengerID: " << PassengerID << " GetOnOffTime: " << GetOnOffTime
       << " PassengerType: " << PassengerType << " statue: " << statue;
    return os;
}



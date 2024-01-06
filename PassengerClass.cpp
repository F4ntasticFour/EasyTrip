#include "PassengerClass.h"

PassengerClass::PassengerClass() {
}

PassengerClass::PassengerClass(const TimeClass& ArrivalTime, const int StartStation, int EndStation, int PassengerID,
                               const std::string& passengerType, const std::string& statue)
    : ArrivalTime(ArrivalTime), StartStation(StartStation), EndStation(EndStation), PassengerID(PassengerID),
      PassengerType(passengerType), statue(statue) {
}

// Getters
TimeClass PassengerClass::getArrivalTime() {
    return ArrivalTime;
}

TimeClass PassengerClass::getLeaveTime() {
    return LeaveTime;
}

TimeClass PassengerClass::getOnTime() {
    return GetOnTime;
}

int PassengerClass::getStartStation(){
    return StartStation;
}

int PassengerClass::getEndStation(){
    return EndStation;
}

TimeClass PassengerClass::getGetOnOffTime(){
    return GetOnOffTime;
}

std::string PassengerClass::getPassengerType() const{
    return PassengerType;
}

int PassengerClass::getPassengerID(){
    return PassengerID;
}

std::string PassengerClass::getPassengerDirection() {
    return PassengerDirection;
}

// Setters
void PassengerClass::setArrivalTime(TimeClass ArrivalTime) {
    this->ArrivalTime = ArrivalTime;
}

void PassengerClass::setLeaveTime(TimeClass LeaveTime) {
    this->LeaveTime = LeaveTime;
}

void PassengerClass::setGetOnTime(TimeClass OnTime) {
    GetOnTime = OnTime;
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

void PassengerClass::setPassengerDirection(const std::string& passengerDirection) {
    PassengerDirection = passengerDirection;
}

std::string PassengerClass::getStatue() const {
    return statue;
}


int PassengerClass::getPriority() const {
    if (getPassengerType() == "SP") {
        if (getStatue() == "Aged" || getStatue() == "aged" || getStatue() == "Promoted") {
            return 1;
        } if (getStatue() == "POD" ) {
            return 2;
        } if (getStatue() == "Pregnant") {
            return 3;
        }
    }
    return 4;
}

void PassengerClass::promotePassenger() {
    if (PassengerType == "Np") {
        statue="Promoted";
    }
}



bool PassengerClass::operator==(const PassengerClass& rhs) const {
    return getPriority() == rhs.getPriority();
}
bool PassengerClass::operator!=(const PassengerClass& rhs) const {
    return !(rhs == *this);
}


void PassengerClass::printPassenger() {
    std::cout<<"Passenger ID: "<<getPassengerID()<<std::endl;
    std::cout<<"Passenger Type: "<<getPassengerType()<<std::endl;
    std::cout<<"Start Station: "<<getStartStation()<<std::endl;
    std::cout<<"End Station: "<<getEndStation()<<std::endl;
    std::cout<<"Arrival Time: "<<getArrivalTime()<<std::endl;
    std::cout<<"Leave Time: "<<getLeaveTime()<<std::endl;
    std::cout<<"Get On/Off Time: "<<getGetOnOffTime()<<std::endl;
    std::cout<<"Statue: "<<getStatue()<<std::endl;

}

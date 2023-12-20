//
// Created by Safey Elrahman on 04/12/2023.
//
#include "StationClass.h"
#include "PriorityQueue.h"

Station::Station(int number) {
    this->number = number;
}

void Station::addNpPassenger(PassengerClass* Passenger) {
    NPpassengers.insertAtBeg(*Passenger);
}

void Station::addWpPassenger(PassengerClass* Passenger) {
    WPpassengers.enqueue(*Passenger);
}

void Station::addSpPassenger(PassengerClass* Passenger) {
    SPpassengers.enqueue(*Passenger, Passenger->getPriority());
}

void Station::removeNpPassenger(PassengerClass* Passenger) {
    NPpassengers.remove(*Passenger);
}

PassengerClass Station::removeWpPassenger() {
    PassengerClass passenger = WPpassengers.frontElement();
    WPpassengers.dequeue();
    return passenger;
}

PassengerClass Station::removeSpPassenger() {
    PassengerClass passenger = SPpassengers.frontElement();
    SPpassengers.dequeue();
    return passenger;
}

int Station::getStationNumber() {
    return number;
}

void Station::setStationNumber(int number) {
    this->number = number;
}


void Station::addFwBus(BusClass* Bus) {
    FWbuses.enqueue(*Bus);
}

void Station::addBwBus(BusClass* Bus) {
    BWbuses.enqueue(*Bus);
}

BusClass Station::removeFwBus() {
    BusClass bus = FWbuses.frontElement();
    FWbuses.dequeue();
    return bus;
}

BusClass Station::removeBwBus() {
    BusClass bus = BWbuses.frontElement();
    BWbuses.dequeue();
    return bus;
}

int Station::getNpPassengerByID(int ID) {
    for (int i = 0; i < NPpassengers.getLength(); i++) {
        if (NPpassengers.getItemAtIndex(i).getPassengerID() == ID) {
            return i;
        }
    }
    std::cerr << "Passenger Not Found" << std::endl;
    return -1;
}


int Station::getCount(const std::string& PassengertType) {
    if (PassengertType == "NP") {
        return NPpassengers.getLength();;
    } else if (PassengertType == "SP") {
        return SPpassengers.size();
    } else if (PassengertType == "WP") {
        return WPpassengers.getLength();
    }
    return 100;
}


Station* Station::operator->() {
    return this;
}

LinkedList<PassengerClass> Station::getNPpassengers() {
    return NPpassengers;
}

//
// Created by Safey Elrahman on 04/12/2023.
//
#include "StationClass.h"
#include "PriorityQueue.h"

Station::Station(int number) {
    this->number = number;
}

void Station::addNpPassenger(PassengerClass* Passenger) {
    NPpassengers.insertAtBeg(Passenger);
}

void Station::addWpPassenger(PassengerClass* Passenger) {
    WPpassengers.enqueue(Passenger);
}

void Station::addSpPassenger(PassengerClass* Passenger) {
    SPpassengers.enqueue(Passenger, Passenger->getPriority());
}

void Station::leaveNpPassenger(PassengerClass* Passenger) {
    NPpassengers.remove(Passenger);
}

PassengerClass* Station::removeNpPassenger() {
    PassengerClass* Passenger = NPpassengers.getItemAtIndex(0);
    NPpassengers.remove(Passenger);
    return Passenger;
}

PassengerClass* Station::removeWpPassenger() {
    PassengerClass* passenger = WPpassengers.frontElement();
    WPpassengers.dequeue();
    return passenger;
}

PassengerClass* Station::removeSpPassenger() {
    PassengerClass* passenger = SPpassengers.frontElement();
    SPpassengers.dequeue();
    return passenger;
}

int Station::getStationNumber() const {
    return number;
}

void Station::setStationNumber(int number) {
    this->number = number;
}


void Station::addFwBus(BusClass* Bus) {
    FWbuses.enqueue(Bus);
}

void Station::addBwBus(BusClass* Bus) {
    BWbuses.enqueue(Bus);
}

BusClass* Station::getFwBus() {
    return FWbuses.frontElement();
}

BusClass* Station::getBwBus() {
    return BWbuses.frontElement();
}

BusClass* Station::removeFwBus() {
    BusClass* bus = FWbuses.frontElement();
    FWbuses.dequeue();
    return bus;
}
bool Station::addPassenger(PassengerClass* Passenger) {
    if (Passenger->getPassengerType() == "NP") {
        this[Passenger->getStartStation()].addNpPassenger(Passenger);
        return true;
    }
    if (Passenger->getPassengerType() == "SP") {
        this[Passenger->getStartStation()].addSpPassenger(Passenger);
        return true;
    }
    if (Passenger->getPassengerType() == "WP") {
        this[Passenger->getStartStation()].addWpPassenger(Passenger);
        return true;
    }
    return false;
}

BusClass* Station::removeBwBus() {
    BusClass* bus = BWbuses.frontElement();
    BWbuses.dequeue();
    return bus;
}

bool Station::isFwBusEmpty() {
    return FWbuses.isEmpty();
}

bool Station::isBwBusEmpty() {
    return BWbuses.isEmpty();
}

PassengerClass* Station::getNpPassengerByID(int ID) {
    int i = 0;
    if (NPpassengers.isEmpty()) {
        return nullptr; // Return a default-constructed object or handle the case appropriately.
    }
    while (i < NPpassengers.getLength()) {
        PassengerClass* currentPassenger = NPpassengers.getItemAtIndex(i);
        if (currentPassenger->getPassengerID() == ID) {
            currentPassenger->printPassenger();
            return currentPassenger;
        }
        i++;
    }
    return nullptr; // Return a default-constructed object or handle the case appropriately.
}

PassengerClass* Station::getNpPassenger(int index) {
    PassengerClass* currentPassenger = NPpassengers.getItemAtIndex(index);
    this->removeNpPassenger();
    return currentPassenger;
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

LinkedList<PassengerClass *> Station::getNPpassengers() {
    return NPpassengers;
}

PriorityQueue<PassengerClass*> Station::getSPpassengers() {
    return SPpassengers;
}


Queue<PassengerClass*> Station::getWPpassengers() {
    return WPpassengers;
}
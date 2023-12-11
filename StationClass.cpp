//
// Created by Safey Elrahman on 04/12/2023.
//
#include "StationClass.h"
#include "PriorityQueue.h"

Station::Station(int number) {
    this->number = number;
}

void Station::addNpPassenger(PassengerClass* Passenger) {
    NPpassengers.insertAtEnd(*Passenger);
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

LinkedList<PassengerClass> Station::getNPpassengers() {
    return NPpassengers;
}

void Station::setStationNumber(int number) {
    this->number = number;
}


void Station::addFwBus(BusClass * Bus) {
    FWbuses.enqueue(*Bus);
}

void Station::addBwBus(BusClass * Bus) {
    BWbuses.enqueue(*Bus);
}
BusClass Station::getFwBus() {
    return FWbuses.frontElement();

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

PassengerClass * Station::getNpPassengerByID(int ID) {
    int i = 0;
    if (NPpassengers.isEmpty()) {
        return new PassengerClass(); // Return a default-constructed object or handle the case appropriately.
    }
    while (i < NPpassengers.getLength()) {
        PassengerClass currentPassenger = NPpassengers.getItemAtIndex(i);
        if (currentPassenger.getPassengerID() == ID) {
            return new PassengerClass(currentPassenger);
        }
        i++;
    }
    return new PassengerClass(); // Return a default-constructed object or handle the case appropriately.
}

Queue<BusClass> Station::getBusQueue() {
    return FWbuses;
}


Station * Station::operator->() {
    return this;
}
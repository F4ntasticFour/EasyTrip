//
// Created by Safey Elrahman on 04/12/2023.
//
#include "StationClass.h"
#include "PriorityQueue.h"

Station::Station(int number) {
    this->number = number;
}

void Station::addNpPassenger(PassengerClass * Passenger) {
    NPpassengers.insertAtEnd(* Passenger);
}

void Station::addWpPassenger(PassengerClass * Passenger) {
    WPpassengers.enqueue(* Passenger);
}
void Station::addSpPassenger(PassengerClass * Passenger) {
    SPpassengers.enqueue(* Passenger, Passenger->getPriority());
}
void Station::removeNpPassenger(PassengerClass * Passenger) {
    NPpassengers.remove(* Passenger);
}

void Station::removeWpPassenger(PassengerClass * Passenger) {
    WPpassengers.dequeue();
}
void Station::removeSpPassenger(PassengerClass * Passenger) {
    SPpassengers.dequeue();
}
int Station::getStationNumber() {
    return number;
}
void Station::setStationNumber(int number) {
    this->number = number;
}
void Station::addFwBus(BusClass bus) {
    FWbuses.enqueue(bus);
}
void Station::addBwBus(BusClass bus) {
    BWbuses.enqueue(bus);
}
void Station::removeFwBus() {
    FWbuses.dequeue();
}
void Station::removeBwBus() {
    BWbuses.dequeue();
}
void Station::addWaitingBus(BusClass * Bus) {
    WaitingBuses.enqueue(* Bus);
}

#include "StationClass.h"

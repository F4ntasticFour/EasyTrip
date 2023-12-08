//
// Created by Safey Elrahman on 04/12/2023.
//
#include "StationClass.h"
#include "PriorityQueue.h"

Station::Station(int number) {
    this->number = number;
}
void Station::addNpPassenger(PassengerClass passenger) {
    NPpassengers.insertAtEnd(passenger);
}
void Station::addWpPassenger(PassengerClass passenger) {
    WPpassengers.enqueue(passenger);
}
void Station::addSpPassenger(PassengerClass passenger) {
    SPpassengers.enqueue(passenger, passenger.getPriority());
}
void Station::removeNpPassenger(PassengerClass passenger) {
    NPpassengers.remove(passenger);
}
void Station::removeWpPassenger() {
    WPpassengers.dequeue();
}
void Station::removeSpPassenger() {
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

#include "StationClass.h"

//
// Created by Safey Elrahman on 04/12/2023.
//

#include "StationClass.h"

Station::Station(string name) {
    this->name = name;
}
void Station::addNpPassenger(PassengerClass passenger) {
    NPpassengers.insertAtEnd(passenger);
}
void Station::addWpPassenger(PassengerClass passenger) {
    WPpassengers.insertAtEnd(passenger);
}
void Station::addSpPassenger(PassengerClass passenger) {
    SPpassengers.enqueue(passenger, passenger.getPriority());
}
void Station::removeNpPassenger(PassengerClass passenger) {
    NPpassengers.remove(passenger);
}
void Station::removeWpPassenger(PassengerClass passenger) {
    WPpassengers.remove(passenger);
}
void Station::removeSpPassenger(PassengerClass passenger) {
    SPpassengers.dequeue();
}
string Station::getName() {
    return name;
}
void Station::setName(string name) {
    this->name = name;
}

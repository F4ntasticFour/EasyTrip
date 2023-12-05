
#include "StationCLass.h"
#include "PriorityQueue.h"


Station::Station(int number) {
    this->number = number;
}
void Station::addNpPassenger(PassengerClass passenger) {
    NPpassengers.insertAtEnd(passenger);
}
void Station::addWpPassenger(PassengerClass passenger) {
    WPpassengers.insertAtEnd(passenger);
}
void Station::addSpPassenger(PassengerClass passenger) {
    SPpassengers.enqueue(passenger, passenger.getPriority();
}
void Station::removeNpPassenger(PassengerClass passenger) {
    NPpassengers.remove(passenger);
}
void Station::removeWpPassenger(PassengerClass passenger) {
    WPpassengers.remove(passenger);
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


// #include "EventClass.h"
//
// Event::Event(TimeClass eventTime, int passengerID, int startStation, int endStation, char type) {
//     this->eventTime = eventTime;
//     this->passengerID = passengerID;
//     this->startStation = startStation;
//     this->endStation = endStation;
//     this->type = type;
//     this->C = nullptr;
// }
//
// char Event::getType() {
//     return type;
// }
//
// void Event::setTime(TimeClass& eventTime) {
//     this->eventTime = eventTime;
// }
// TimeClass Event::getTime() {
//     return eventTime;
// }
//
// ArriveEvent::ArriveEvent(TimeClass ArrivalTime,int passengerID, int startStation, int endStation) : Event(ArrivalTime,passengerID,startStation,endStation,'A' ) {
//     this->ArrivalTime = ArrivalTime;
//     this->passengerID = passengerID;
//     this->startStation = startStation;
//     this->endStation = endStation;
//     this->C = nullptr;
// }
// void ArriveEvent::execute() {
//     CompanyClass *C;
// //    we need to add passengerid to the constructor of passenger class
//     PassengerClass* Passenger = new PassengerClass(passengerID,ArrivalTime,startStation,endStation,GetOnOffTime,"np");
//     C->addPassenger(Passenger);
// }
// LeaveEvent::LeaveEvent(TimeClass LeaveTime,int passengerID, int startStation,int endStation) : Event(LeaveTime,passengerID,startStation,endStation,'L') {
//     this->LeaveTime = LeaveTime;
//     this->passengerID = passengerID;
//     this->startStation = startStation;
//     this->endStation = endStation;
//     this->C = nullptr;
// }
//
// void LeaveEvent::execute() {
//     CompanyClass *C;
//     PassengerClass* Passenger = new PassengerClass(passengerID,LeaveTime,startStation,endStation,GetOnOffTime,"np");
//     //why do we need to create a new bus here? leave event is called when a passenger asked to leave and hasnt been picked up yet
//     //so the logic should be like this
//     // C->leavePassenger(Passenger);
//     BusClass* Bus = new BusClass();
//     C->addFinshedPassengers(Passenger,Bus);
// }
//
//
//
//
//

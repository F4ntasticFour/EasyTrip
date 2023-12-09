#include "EventClass.h"
#include "FileHandler.h"

Event::Event(char eventType,TimeClass eventTime, PassengerClass* P, CompanyClass* C)
    : eventTime(eventTime), P(P), C(C) {
}

TimeClass Event::getTime() {
    return eventTime;
}

ArriveEvent::ArriveEvent(TimeClass ArrivalTime, PassengerClass* P, CompanyClass* C)
: Event(eventType = 'A',ArrivalTime, P, C), ArrivalTime(ArrivalTime) {
}

void ArriveEvent::execute(CompanyClass* C) {
    FileHandler file("text");
    Queue<std::string> eventList = file.getEventList();
    std::string line = eventList.frontElement();
    eventList.dequeue();
    std::string delimiter = " ";
    std::string token = line.substr(0, line.find(delimiter));
    std::string PassengerType = token;
    line.erase(0, line.find(delimiter) + delimiter.length());
    token = line.substr(0, line.find(delimiter));
    token = token.substr(0, token.find(':'));
    TimeClass ArrivalTime = TimeClass(token[1], token[2]);
    line.erase(0, line.find(delimiter) + delimiter.length());
    token = line.substr(0, line.find(delimiter));
    int PassengerID = std::stoi(token);
    line.erase(0, line.find(delimiter) + delimiter.length());
    token = line.substr(0, line.find(delimiter));
    int StartStation = std::stoi(token);
    line.erase(0, line.find(delimiter) + delimiter.length());
    token = line.substr(0, line.find(delimiter));
    int EndStation = std::stoi(token);
    line.erase(0, line.find(delimiter) + delimiter.length());
    token = line.substr(0, line.find(delimiter));
    std::string statue = token;

    PassengerClass* P = new PassengerClass(ArrivalTime,StartStation, EndStation, PassengerID, PassengerType, statue);
    C->addPassenger(P);
}

LeaveEvent::LeaveEvent(TimeClass LeaveTime, PassengerClass* P, CompanyClass* C)
    : Event(eventType = 'L',LeaveTime, P, C), LeaveTime(LeaveTime) {
}

void LeaveEvent::execute(CompanyClass* C) {
    FileHandler file("text");
    Queue<std::string> eventList = file.getEventList();
    std::string line = eventList.frontElement();
    eventList.dequeue();
    std::string delimiter = " ";
    std::string token = line.substr(0, line.find(delimiter));
    std::string PassengerType = token;
    line.erase(0, line.find(delimiter) + delimiter.length());
    token = line.substr(0, line.find(delimiter));
    token = token.substr(0, token.find(':'));
    TimeClass LeaveTime = TimeClass(token[1], token[2]);
    line.erase(0, line.find(delimiter) + delimiter.length());
    token = line.substr(0, line.find(delimiter));
    int PassengerID = std::stoi(token);
    line.erase(0, line.find(delimiter) + delimiter.length());
    token = line.substr(0, line.find(delimiter));
    int StartStation = std::stoi(token);
    line.erase(0, line.find(delimiter) + delimiter.length());


    C->leavePassenger(P, LeaveTime);
}

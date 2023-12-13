#include "EventClass.h"
#include "FileHandler.h"
#include <sstream>
#include <iostream>

using namespace std;

Event::Event(TimeClass eventTime, PassengerClass* P, CompanyClass* C)
    : eventTime(eventTime), P(P), C(C) {
}

void Event::setCompany(CompanyClass* company) {
    this->C = company;
}

void Event::setPassenger(PassengerClass* passenger) {
    this->P = passenger;
}

void Event::setEventQueue(Queue<std::vector<std::string>> eventQueue) {
    this->eventQueue = eventQueue;
}

void Event::setFile(std::string filename) {
    this->file = filename;
}

CompanyClass* Event::getCompany() {
    return C;
}

PassengerClass* Event::getPassenger() {
    return P;
}

Queue<std::vector<std::string>> Event::getEventQueue() {
    return eventQueue;
}

std::string Event::getFile() {
    return file;
}

ArriveEvent::ArriveEvent(TimeClass ArrivalTime, PassengerClass* P, CompanyClass* C)
    : Event(ArrivalTime, P, C) {
}

void ArriveEvent::execute() {
    cout << C->addPassenger(P) << " Passengers in the system" << endl;
}

LeaveEvent::LeaveEvent(TimeClass LeaveTime, PassengerClass* P, CompanyClass* C)
    : Event(LeaveTime, P, C) {
}

void LeaveEvent::execute() {
    cout << C->leavePassenger(P) << " Passengers left system" << endl;
}

bool processEvent(TimeClass Time, CompanyClass* company, Queue<std::vector<std::string>> eventQueue, int numEvents) {
    while (numEvents != 0) {
        std::vector<std::string> line = eventQueue.frontElement();
        std::string eventType = line[0];

        if (eventType == "A") {
            std::string PassengerType = line[1];
            std::istringstream iss(line[2]);
            std::string arrivaltime;
            std::getline(iss, arrivaltime, ':');
            int hours = std::stoi(arrivaltime);
            std::getline(iss, arrivaltime);
            int minutes = std::stoi(arrivaltime);
            TimeClass ArrivalTime(hours, minutes);
            int PassengerID = std::stoi(line[3]);
            int StartStation = std::stoi(line[4]);
            int EndStation = std::stoi(line[5]);
            std::string statue = line[6];

            if (statue.empty()) {
                statue = "Normal";
            }
            if (Time == ArrivalTime) {
                auto* P = new PassengerClass(ArrivalTime, StartStation, EndStation, PassengerID, PassengerType, statue);
                ArriveEvent arriveEvent(ArrivalTime, P, company);
                cout<<PassengerType<<" "<<ArrivalTime<<" "<<PassengerID<<" "<<StartStation<<" "<<EndStation<<" "<<statue<<endl;
                arriveEvent.execute();
                return true;
            }
            return false;
        } else if (eventType == "L") {
            std::string PassengerType = line[1];
            std::istringstream iss(line[2]);
            std::string arrivaltime;
            std::getline(iss, arrivaltime, ':');
            int hours = std::stoi(arrivaltime);

            std::getline(iss, arrivaltime);

            int minutes = std::stoi(arrivaltime);

            TimeClass leaveTime(hours, minutes);
            if (Time == leaveTime) {
                PassengerClass* P = company->getPassengerByID(std::stoi(line[3]));
                LeaveEvent leaveEvent(leaveTime, P, company);
                leaveEvent.execute();
                return true;
            }
            return false;
        }
    }
    return false;
}

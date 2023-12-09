#ifndef EASYTRIP_EVENTCLASS_H
#define EASYTRIP_EVENTCLASS_H

#include "TimeClass.h"
#include "PassengerClass.h"
#include "CompanyClass.h"
#include "BusClass.h"
#include "StationClass.h"
#include "FileHandler.h"

class Event {
public:
    Event(char eventType,TimeClass eventTime, PassengerClass* P, CompanyClass* C);
    void setTime(TimeClass& eventTime);
    TimeClass getTime();

protected:
    char eventType;
    TimeClass eventTime;
    PassengerClass* P;
    CompanyClass* C;
};

class ArriveEvent : public Event {
public:
    ArriveEvent(TimeClass ArrivalTime, PassengerClass* P, CompanyClass* C);
    void execute(CompanyClass* C);

private:
    TimeClass ArrivalTime;
};

class LeaveEvent : public Event {
public:
    LeaveEvent(TimeClass LeaveTime, PassengerClass* P, CompanyClass* C);
    void execute(CompanyClass* C);

private:
    TimeClass LeaveTime;
};

#endif //EASYTRIP_EVENTCLASS_H

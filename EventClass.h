//
// Created by Safey Elrahman on 04/12/2023.
//

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wc++11-extensions"
#ifndef EASYTRIP_EVENTCLASS_H
#define EASYTRIP_EVENTCLASS_H
#include "TimeClass.h"
#include "CompanyClass.h"
class Event{
protected:
    char type;
    Time eventTime;
    int startStation;
    int endStation;
    int passengerID;
    Time GetOnOffTime=Time(0,1/6);
    CompanyClass *C;

public:
    Event(Time eventTime, int passengerID, int startStation, int endStation, char type);
    char getType();
    void setTime(Time &eventTime);

    Time getTime();

    virtual void  execute()=0;
};

class ArriveEvent: public Event{
protected:
    CompanyClass *C;
    Time ArrivalTime;

public:
    ArriveEvent(Time ArrivalTime,int passengerID, int startStation, int endStation);
    void execute() override;
};
class LeaveEvent: public Event{
protected:
    CompanyClass *C;
    Time LeaveTime;


public:
    LeaveEvent(Time LeaveTime,int passengerID, int startStation, int endStation);
    void execute() override;
};


#endif //EASYTRIP_EVENTCLASS_H

#pragma clang diagnostic pop
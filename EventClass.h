// //
// // Created by Safey Elrahman on 04/12/2023.
// //
//
// #pragma clang diagnostic push
// #pragma clang diagnostic ignored "-Wc++11-extensions"
// #ifndef EASYTRIP_EVENTCLASS_H
// #define EASYTRIP_EVENTCLASS_H
// #include "TimeClass.h"
// #include "CompanyClass.h"
// class Event{
// protected:
//     char type;
//     TimeClass eventTime;
//     int startStation;
//     int endStation;
//     int passengerID;
//     TimeClass GetOnOffTime=TimeClass(0,1/6);
//     CompanyClass *C;
//
// public:
//     Event(TimeClass eventTime, int passengerID, int startStation, int endStation, char type);
//     char getType();
//     void setTime(TimeClass &eventTime);
//
//     TimeClass getTime();
//
//     virtual void  execute()=0;
// };
//
// class ArriveEvent: public Event{
// protected:
//     CompanyClass *C;
//     TimeClass ArrivalTime;
//
// public:
//     ArriveEvent(TimeClass ArrivalTime,int passengerID, int startStation, int endStation);
//     void execute() override;
// };
// class LeaveEvent: public Event{
// protected:
//     CompanyClass *C;
//     TimeClass LeaveTime;
//
//
// public:
//     LeaveEvent(TimeClass LeaveTime,int passengerID, int startStation, int endStation);
//     void execute() override;
// };
//
//
// #endif //EASYTRIP_EVENTCLASS_H
//
// #pragma clang diagnostic pop
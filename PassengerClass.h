//
// Created by Safey Elrahman on 04/12/2023.
//

#ifndef EASYTRIP_PASSENGERCLASS_H
#define EASYTRIP_PASSENGERCLASS_H
#include "TimeClass.h"

#include <string>

class PassengerClass {
private:
    TimeClass ArrivalTime;
    TimeClass LeaveTime;
    int StartStation;
    int EndStation;
    int PassengerID;
    const TimeClass GetOnOffTime = TimeClass(0,1/6);
    std::string PassengerType;
    std::string statue;
public:
    // Constructor
    PassengerClass();
    PassengerClass(TimeClass ArrivalTime,const int& StartStation, int& EndStation,int PassengerID,const std::string& passengerType ,const std::string& statue);

    // Getters
    TimeClass getArrivalTime();
    TimeClass getLeaveTime();
    int getStartStation() const;
    int getEndStation() const;
    TimeClass getGetOnOffTime() const;
    std::string getPassengerType() const;
    int getPassengerID() const;


    // Setters
    void setArrivalTime(TimeClass ArrivalTime);
    void setLeaveTime(TimeClass LeaveTime);
    void setStartStation(const int& startStation);
    void setEndStation(const int& endStation);
    void setPassengerType(const std::string& passengerType);
    void setStatue(const std::string& statue);
    void setPassengerID(int passengerID);
    int getPriority() const;
    std::string getStatue() const;
    // Operator Overloading
    bool operator==(const PassengerClass& lhs) const;

};


#endif //EASYTRIP_PASSENGERCLASS_H

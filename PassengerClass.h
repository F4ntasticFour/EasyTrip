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
    TimeClass GetOnTime;
    int StartStation;
    int EndStation;
    int PassengerID;
    std::string PassengerDirection;
    const TimeClass GetOnOffTime = TimeClass(0,1/6);
    std::string PassengerType;
    std::string statue;
public:
    //Default Constructor
    PassengerClass();
    // Constructor
    PassengerClass(const TimeClass& ArrivalTime, int StartStation, int EndStation,int PassengerID,const std::string& passengerType ,const std::string& statue);

    // Getters
    TimeClass getArrivalTime();
    TimeClass getLeaveTime();
    TimeClass getOnTime();
    int getStartStation();
    int getEndStation();
    TimeClass getGetOnOffTime();
    std::string getPassengerType() const;
    int getPassengerID();
    int getPriority() const;
    std::string getPassengerDirection();

    // Setters
    void setArrivalTime(TimeClass ArrivalTime);
    void setLeaveTime(TimeClass LeaveTime);
    void setGetOnTime(TimeClass OnTime);
    void setStartStation(int startStation);
    void setEndStation(int endStation);
    void setPassengerType(const std::string& passengerType);
    void setStatue(const std::string& statue);
    void setPassengerID(int passengerID);
    void setPassengerDirection(const std::string& passengerDirection);
    void promotePassenger();
    std::string getStatue() const;

    // Operator Overloading
    bool operator==(const PassengerClass& lhs) const;
    bool operator!=(const PassengerClass& lhs) const;
    PassengerClass* operator&();

    std::ostream& operator<<(std::ostream& os) const;
    void printPassenger();

};


#endif //EASYTRIP_PASSENGERCLASS_H

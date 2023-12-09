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
    int StartStation;
    int EndStation;
    int passengerID = rand();
    const TimeClass GetOnOffTime = TimeClass(0,1/6);
    std::string PassengerType;
    std::string statue;
public:
    // Constructor
//    TODO: ADD PASSENGER ID as a random number, constant get on off time = 1/6min

    PassengerClass();
    PassengerClass(TimeClass& ArrivalTime, const int& StartStation, int& EndStation, const std::string& passengerType ,const std::string& statue);

    // Getters
    TimeClass getArrivalTime() const;
    int getStartStation() const;
    int getEndStation() const;
    TimeClass getGetOnOffTime() const;
    std::string getPassengerType() const;
    int getPassengerID() const;

    // Setters
    void setArrivalTime(TimeClass& arrivalTime);
    void setStartStation(const int& startStation);
    void setEndStation(const int& endStation);
    void setPassengerType(const std::string& passengerType);
    void setStatue(const std::string& statue);
    void setPassengerID(int passengerID);
    int getPriority() const;
    std::string getStatue() const;

    bool operator==(const PassengerClass& lhs) const;

};


#endif //EASYTRIP_PASSENGERCLASS_H

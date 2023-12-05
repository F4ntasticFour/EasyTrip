//
// Created by Safey Elrahman on 04/12/2023.
//

#ifndef EASYTRIP_PASSENGERCLASS_H
#define EASYTRIP_PASSENGERCLASS_H
#include "TimeClass.h"

#include <string>

class PassengerClass {
private:
    Time ArrivalTime;
    int StartStation;
    int EndStation;
    Time GetOnOffTime;
    std::string PassengerType;
    std::string statue;
public:
    // Constructor
    PassengerClass(Time& ArrivalTime, const int& StartStation, int& EndStation, Time& GetOnOffTime, const std::string& passengerType);

    // Getters
    Time getArrivalTime() const;
    int getStartStation() const;
    int getEndStation() const;
    Time getGetOnOffTime() const;
    std::string getPassengerType() const;

    // Setters
    void setArrivalTime(const Time& arrivalTime);
    void setStartStation(const int& startStation);
    void setEndStation(const int& endStation);
    void setGetOnOffTime(Time getOnOffTime);
    void setPassengerType(const std::string& passengerType);
    void setStatue(const std::string& statue);
    int getPriority() const;
    std::string getStatue() const;
    bool operator==(const PassengerClass& lhs) const;

};


#endif //EASYTRIP_PASSENGERCLASS_H

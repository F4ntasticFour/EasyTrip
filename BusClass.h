#ifndef EASYTRIP_BUSCLASS_H
#define EASYTRIP_BUSCLASS_H

#include "TimeClass.h"
#include <string>

class BusClass {
private:
    std::string BusType;
    int BusCapacity;
    int JourneyCompleted;
    Time CheckUpTime;
    int BusCurrentStation;

public:

    BusClass() = default;

    BusClass(const std::string& busType, int busCapacity, int journeyCompleted, Time checkUpTime, int busCurrentStation);

    std::string getBusType() const;
    int getBusCapacity() const;
    int getJourneyCompleted() const;
    int getBusCurrentStation() const;
//    priority queue (priorty=nearest station) of passengers
    Time getCheckUpTime() const;

    // Setters
    void setBusType(const std::string& busType);
    void setBusCapacity(int busCapacity);
    void setJourneyCompleted(int journeyCompleted);
    void setCheckUpTime(Time checkUpTime);

    //Member Functions
    void performMaintenance();
    bool isSuitableForPassengerType(const std::string& passengerType) const;
    //TODO: add onBoarding and gotOff functions
};

#endif //EASYTRIP_BUSCLASS_H

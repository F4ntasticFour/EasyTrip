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

public:

    BusClass(const std::string& busType, int busCapacity, int journeyCompleted, Time checkUpTime);

    std::string getBusType() const;
    int getBusCapacity() const;
    int getJourneyCompleted() const;
    Time getCheckUpTime() const;

    // Setters
    void setBusType(const std::string& busType);
    void setBusCapacity(int busCapacity);
    void setJourneyCompleted(int journeyCompleted);
    void setCheckUpTime(Time checkUpTime);

    void performMaintenance();


    bool isSuitableForPassengerType(const std::string& passengerType) const;
};

#endif //EASYTRIP_BUSCLASS_H

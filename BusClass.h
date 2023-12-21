#ifndef EASYTRIP_BUSCLASS_H
#define EASYTRIP_BUSCLASS_H

#include "TimeClass.h"
#include "PriorityQueue.h"
#include <string>

#include "PassengerClass.h"

class CompanyClass;

class BusClass {
private:
    int BusID;
    std::string BusType;
    int BusCapacity;
    TimeClass TimeBetweenStations;
    int JourneyCompleted;
    TimeClass CheckUpTime;
    TimeClass TimeAtStation = TimeClass(0,0);
    int BusCurrentStation;
    int TripsBeforeCheckUp;
    std::string busDirection;
    PriorityQueue<PassengerClass*> PassengersOnBoard;


public:
    BusClass() = default;

    BusClass(int BusID, const std::string& busType,TimeClass TimeBetweenStations, int busCapacity, TimeClass checkUpTime,
             int TripsBeforeCheckUp);

    std::string getBusType() const;

    int getBusCapacity() const;

    int getJourneyCompleted() const;

    int getBusCurrentStation() const;

    TimeClass getCheckUpTime() const;

    // Setters
    void setBusType(const std::string& busType);

    void setBusCapacity(int busCapacity);

    void setJourneyCompleted(int journeyCompleted);

    void setCheckUpTime(TimeClass checkUpTime);

    //Member Functions
    void performMaintenance();

    bool isSuitableForPassengerType(const std::string& passengerType) const;

    bool onBoardPassenger(PassengerClass* Passenger);

    bool offBoardPassenger(CompanyClass* Company);

    bool offBoardAllPassenger(CompanyClass* Company);

    bool moveToNextStation(CompanyClass* Company);


};

#endif //EASYTRIP_BUSCLASS_H

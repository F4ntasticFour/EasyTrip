#ifndef EASYTRIP_BUSCLASS_H
#define EASYTRIP_BUSCLASS_H

#include "TimeClass.h"
#include "Queue.h"
#include <string>
#include "PriorityQueue.h"

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
    bool isMoved;
    std::string busDirection;
    Queue<PassengerClass*> PassengersOnBoard;


public:
    BusClass() = default;

    BusClass(int BusID, const std::string& busType,TimeClass TimeBetweenStations, int busCapacity, TimeClass checkUpTime,
             int TripsBeforeCheckUp,int BusCurrentStation);

    std::string getBusType() const;

    int getBusCapacity() const;

    int getJourneyCompleted() const;

    int getBusCurrentStation();

    int getBusID() const;

    TimeClass getCheckUpTime() const;

    bool getIsMoved();

    std::string getBusDirection();

    // Setters
    void setBusType(const std::string& busType);

    void setBusCapacity(int busCapacity);

    void setJourneyCompleted(int journeyCompleted);

    void setCheckUpTime(TimeClass checkUpTime);

    void setBusCurrentStation(int BusCurrentStation);

    bool setIsMoved(bool Moved);

    void setBusDirection(std::string Direction);

    void tickJourneyCompleted();

    void clearJourneyCompleted();

    //Member Functions
    void performMaintenance();

    bool onBoardPassenger(PassengerClass* Passenger);

    void offBoardPassenger(CompanyClass* Company, TimeClass& Time);

    int getOnBoardPassengerCount();

    bool offBoardAllPassenger(CompanyClass* Company);



};

#endif //EASYTRIP_BUSCLASS_H

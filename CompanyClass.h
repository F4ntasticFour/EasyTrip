#ifndef EASYTRIP_COMPANYCLASS_H
#define EASYTRIP_COMPANYCLASS_H

#include "Queue.h"
#include "StationClass.h"
#include "BusClass.h"
#include "PassengerClass.h"

class CompanyClass {
private:
    Queue<PassengerClass *> FinishedPassengers;
    int StationCount;
    Queue<BusClass *> BusCheckUpQueue;
    Queue<BusClass *> MovingBus;
    TimeClass TimeBetweenStations;
    int NumberOfWCBuses;
    int NumberOfMBuses;
    int WCBusCapacity;
    int MBusCapacity;
    int TripsBeforeCheckup;
    TimeClass CheckupDurationWCBus;
    TimeClass CheckupDurationMBus;
    Station StationList[];

public:
    CompanyClass(int StationCount, TimeClass TimeBetweenStations, int NumberOfWCBuses, int NumberOfMBuses,
                 int WCBusCapacity, int MBusCapacity, int TripsBeforeCheckup, TimeClass CheckupDurationWCBus,
                 TimeClass CheckupDurationMBus);

    bool addPassenger(PassengerClass* Passenger);

    bool addFinshedPassengers(PassengerClass* Passenger, BusClass* Bus);

    bool leavePassenger(PassengerClass* Passenger,TimeClass LeaveTime);

    bool busMoving(BusClass* Bus);

    bool busAtCheckup(BusClass* Bus);
};

#endif //EASYTRIP_COMPANYCLASS_H

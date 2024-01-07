#ifndef EASYTRIP_COMPANYCLASS_H
#define EASYTRIP_COMPANYCLASS_H

#include "Queue.h"
#include "StationClass.h"
#include "BusClass.h"
#include "FileHandler.h"
#include "PassengerClass.h"

class CompanyClass {
private:
    Queue<PassengerClass *> FinishedPassengers;
    int StationCount;
    std::vector<Station> StationList;
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
public:
    CompanyClass(int StationCount, TimeClass TimeBetweenStations, int NumberOfWCBuses, int NumberOfMBuses,
                           int WCBusCapacity, int MBusCapacity, int TripsBeforeCheckup,
                           TimeClass CheckupDurationWCBus, TimeClass CheckupDurationMBus);

    bool addPassenger(PassengerClass* Passenger);

    bool addFinshedPassengers(PassengerClass* Passenger, BusClass* Bus);

    int getCount(int StationID, const std::string& PassengerType);

    bool leavePassenger(PassengerClass* Passenger);

    bool busAtCheckup(BusClass* Bus);

    void moveBus();

    PassengerClass * getPassengerByID(int ID);

    BusClass * getBus();

    int getStationCount() const;



    Queue<PassengerClass *> getFinishedPassengers();

    Station getStation(int ID);

    static void startSimulation(std::string filename);

    void tickCheckup();

    void onBoardPassengers(TimeClass& Time);

    void offBoardPassengers(TimeClass& Time);

    bool ADDFinishedpassengers(PassengerClass *Passenger);

};

#endif //EASYTRIP_COMPANYCLASS_H

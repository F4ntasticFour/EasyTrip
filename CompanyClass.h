
#ifndef EASYTRIP_COMPANYCLASS_H
#define EASYTRIP_COMPANYCLASS_H

#include "Queue.h"
#include "StationClass.h"
#include "BusClass.h"
#include "PassengerClass.h"

class CompanyClass {
private:
    Queue<PassengerClass*> FinishedPassengers;
    Station StationList[100];
    Queue<BusClass*> BusCheckUpQueue;
    Queue<BusClass*> MovingBus;

public:
    bool addPassenger(PassengerClass* Passenger);
    bool addFinshedPassengers(PassengerClass * Passenger,BusClass* Bus);
    bool busMoving(BusClass* Bus);
    bool busAtCheckup(BusClass* Bus);
};

#endif //EASYTRIP_COMPANYCLASS_H

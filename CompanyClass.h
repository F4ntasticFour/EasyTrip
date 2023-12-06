
#ifndef EASYTRIP_COMPANYCLASS_H
#define EASYTRIP_COMPANYCLASS_H

#include "Queue.h"
#include "StationClass.h"
#include "BusClass.h"
#include "PriorityQueue.h"
#include "PassengerClass.h"

class CompanyClass {
private:
    Queue<BusClass*> FinishedBusMbus;
    Queue<BusClass*> FinishedBusWCBus;
    Station StationList[100];
    Queue<BusClass*> CheckUpQueueMbus;
    Queue<BusClass*> CheckUpQueueWCbus;
    Queue<BusClass*> MovingBusMbus;
    Queue<BusClass*> MovingBusWCBus;

public:
    bool busFinshed(BusClass* Bus);
    bool busMoving(BusClass* Bus);
    bool busAtCheckup(BusClass* Bus);
};

#endif //EASYTRIP_COMPANYCLASS_H

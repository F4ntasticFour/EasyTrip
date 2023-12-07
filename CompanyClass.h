
#ifndef EASYTRIP_COMPANYCLASS_H
#define EASYTRIP_COMPANYCLASS_H

#include "Queue.h"
#include "StationClass.h"
#include "BusClass.h"
#include "PriorityQueue.h"
#include "PassengerClass.h"

class CompanyClass {
private:
    Queue<BusClass*> FinishedPassengersBus;
    Station StationList[100];
    Queue<BusClass*> CheckUpQueueMbus;
    Queue<BusClass*> CheckUpQueueWCbus;
//    no need for two kinds
    Queue<BusClass*> MovingBus;

public:
    bool busFinshed(BusClass* Bus);
    bool busMoving(BusClass* Bus);
    bool busAtCheckup(BusClass* Bus);
};

#endif //EASYTRIP_COMPANYCLASS_H

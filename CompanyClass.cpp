// CompanyClass.cpp

#include "CompanyClass.h"



bool CompanyClass::busMoving(BusClass* Bus) {

        MovingBus.enqueue(Bus);
        return true;

}

bool CompanyClass::busAtCheckup(BusClass* Bus) {
    if (Bus->getBusType() == "Mbus" && Bus->getJourneyCompleted() == 5) {
        CheckUpQueueMbus.enqueue(Bus);
        return true;
    } else if (Bus->getBusType() == "WCBus" && Bus->getJourneyCompleted() == 5) {
        CheckUpQueueWCbus.enqueue(Bus);
        return true;
    }
    return false;
//    add passenger (P*){
//    get source station
//    add to station array[srcstation].addpass(P)}
//    leave passenger(P*,src station)

}

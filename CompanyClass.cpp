// CompanyClass.cpp

#include "CompanyClass.h"

bool CompanyClass::busFinshed(BusClass* Bus) {
    // should be chnaged S station when we add the filehandling
    int finalStationNum = 20;
    if (Bus->getBusType() == "Mbus") {
        if (Bus->getBusCurrentStation() == finalStationNum) {
            FinishedBusMbus.enqueue(Bus);
            return true;
        }
    } else if (Bus->getBusType() == "WCBus") {
        if (Bus->getBusCurrentStation() == finalStationNum) {
            FinishedBusWCBus.enqueue(Bus);
            return true;
        }
    }
    return false;
}

bool CompanyClass::busMoving(BusClass* Bus) {
    if (Bus->getBusType() == "Mbus") {
        MovingBusMbus.enqueue(Bus);
        return true;
    } else if (Bus->getBusType() == "WCBus") {
        MovingBusWCBus.enqueue(Bus);
        return true;
    }
    return false;
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
}

#ifndef EASYTRIP_STATIONCLASS_H
#define EASYTRIP_STATIONCLASS_H

#include <string>
#include "PriorityQueue.h"
#include "PassengerClass.h"
#include "LinkedList.h"
#include "Queue.h"
#include "BusClass.h"


class Station {
private:
    int number;
    PriorityQueue<PassengerClass> SPpassengers;
    LinkedList<PassengerClass> NPpassengers;
    Queue<PassengerClass> WPpassengers;
    Queue<BusClass> FWbuses;
    Queue<BusClass> BWbuses;

// queue instead of ll    LinkedList<PassengerClass> WPpassengers;
//List of buses
//list of both directions of route (fwd,bck)

public:

    Station(int number);

    void setStationNumber(int number);

    int getStationNumber();

    void addNpPassenger(PassengerClass passenger);

    void addWpPassenger(PassengerClass passenger);

    void addSpPassenger(PassengerClass passenger);

    void removeNpPassenger(PassengerClass passenger);

    void removeWpPassenger();

    void removeSpPassenger();

    void addFwBus(BusClass bus);

    void addBwBus(BusClass bus);

    void removeFwBus();

    void removeBwBus();

//    add

};


#endif //EASYTRIP_STATIONCLASS_H

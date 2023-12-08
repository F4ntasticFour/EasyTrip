#ifndef EASYTRIP_STATIONCLASS_H
#define EASYTRIP_STATIONCLASS_H

#include "BusClass.h"
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
    Queue<BusClass> WaitingBuses;



public:

    Station(int number);

    void setStationNumber(int number);

    int getStationNumber();

    void addNpPassenger(PassengerClass * Passenger);

    void addWpPassenger(PassengerClass * Passenger);

    void addSpPassenger(PassengerClass * Passenger);

    void removeNpPassenger(PassengerClass * Passenger);

    void removeWpPassenger();

    void removeWpPassenger(PassengerClass * Passenger);

    void removeSpPassenger(PassengerClass * Passenger);

    void addWaitingBus(BusClass * Bus);

    void addFwBus(BusClass bus);

    void addBwBus(BusClass bus);

    void removeFwBus();

    void removeBwBus();



};


#endif //EASYTRIP_STATIONCLASS_H

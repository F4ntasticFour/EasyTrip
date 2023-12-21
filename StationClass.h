#ifndef EASYTRIP_STATIONCLASS_H
#define EASYTRIP_STATIONCLASS_H

#include "BusClass.h"
#include "PriorityQueue.h"
#include "PassengerClass.h"
#include "LinkedList.h"
#include "Queue.h"


class Station {
private:
    int number;
    PriorityQueue<PassengerClass> SPpassengers;
    LinkedList<PassengerClass> NPpassengers;
    Queue<PassengerClass> WPpassengers;
    Queue<BusClass> FWbuses;
    Queue<BusClass> BWbuses;
public:
    Station() = default;

    explicit Station(int number);

    void setStationNumber(int number);

    int getStationNumber();

    void addNpPassenger(PassengerClass * Passenger);

    void addWpPassenger(PassengerClass * Passenger);

    void addSpPassenger(PassengerClass * Passenger);

    void removeNpPassenger(PassengerClass * Passenger);

    PassengerClass removeWpPassenger();

    PassengerClass removeSpPassenger();

    void addFwBus(BusClass * Bus);

    void addBwBus(BusClass * Bus);

    BusClass  getFwBus();

    BusClass getBwBus();

    BusClass removeFwBus();

    BusClass removeBwBus();

    PassengerClass * getNpPassengerByID(int ID);

    int getCount(const std::string&);

    Station * operator->();

    LinkedList<PassengerClass> getNPpassengers();


};


#endif //EASYTRIP_STATIONCLASS_H

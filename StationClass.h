#ifndef EASYTRIP_STATIONCLASS_H
#define EASYTRIP_STATIONCLASS_H

#include <string>
#include "PriorityQueue.h"
#include "PassengerClass.h"
#include "LinkedList.h"


class Station {
public:
    int number;
    PriorityQueue<PassengerClass> SPpassengers;
    LinkedList<PassengerClass> NPpassengers;
    LinkedList<PassengerClass> WPpassengers;

private:

    Station(int number);

    void setStationNumber(int number);

    int getStationNumber();

    void addNpPassenger(PassengerClass passenger);

    void addWpPassenger(PassengerClass passenger);

    void addSpPassenger(PassengerClass SPpassenger);

    void removeNpPassenger(PassengerClass passenger);

    void removeWpPassenger(PassengerClass passenger);

    void removeSpPassenger();

};



#include "StationClass.cpp"

#endif //EASYTRIP_STATIONCLASS_H

//
// Created by Safey Elrahman on 04/12/2023.
//

#ifndef EASYTRIP_STATIONCLASS_H
#define EASYTRIP_STATIONCLASS_H

#include <string>
#include "PriorityQueue.h"
#include "PassengerClass.h"
#include "LinkedList.h"
using namespace std;

class Station {
public:
    string name;
    PriorityQueue<PassengerClass> SPpassengers;
    LinkedList<PassengerClass> NPpassengers;
    LinkedList<PassengerClass> WPpassengers;
    Station(string name);
    void setName(string name);
    string getName();
    void addNpPassenger(PassengerClass passenger);
    void addWpPassenger(PassengerClass passenger);
    void addSpPassenger(PassengerClass SPpassenger);
    void removeNpPassenger(PassengerClass passenger);
    void removeWpPassenger(PassengerClass passenger);
    void removeSpPassenger();
};


#endif //EASYTRIP_STATIONCLASS_H

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
    PriorityQueue<PassengerClass *> SPpassengers;
    LinkedList<PassengerClass *> NPpassengers;
    Queue<PassengerClass *> WPpassengers;
    Queue<BusClass *> FWbuses;
    Queue<BusClass *> BWbuses;
public:
    Station() = default;

    explicit Station(int number);

    void setStationNumber(int number);

    int getStationNumber() const;

    void addNpPassenger(PassengerClass * Passenger);

    void addWpPassenger(PassengerClass * Passenger);

    void addSpPassenger(PassengerClass * Passenger);

    void leaveNpPassenger(PassengerClass* Passenger);

    PassengerClass*  removeNpPassenger();

    PassengerClass* removeWpPassenger();

    PassengerClass* removeSpPassenger();

    void addFwBus(BusClass * Bus);

    void addBwBus(BusClass * Bus);

    BusClass * getFwBus();

    BusClass * getBwBus();

    BusClass * removeFwBus();

    bool addPassenger(PassengerClass * Passenger);

    BusClass * removeBwBus();

    bool isFwBusEmpty();

    bool isBwBusEmpty();

    PassengerClass * getNpPassengerByID(int ID);

    PassengerClass * getNpPassenger(int index);

    int getCount(const std::string&);

    Station * operator->();

    LinkedList<PassengerClass * > getNPpassengers();

    PriorityQueue<PassengerClass*> getSPpassengers();

    Queue<PassengerClass*> getWPpassengers();


};


#endif //EASYTRIP_STATIONCLASS_H

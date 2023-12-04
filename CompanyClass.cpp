//
// Created by Safey Elrahman on 04/12/2023.
//
#include "Queue.h"
#include "StationClass.h"
#include "BusClass.h"
#include "PriorityQueue.h"
#include "PassengerClass.h"
#include "CompanyClass.h"




class CompanyClass{
private:
    Queue<BusClass*> FinishedBusMbus;
    Queue<BusClass*> FinishedBusWCBus;
<<<<<<< HEAD
    Station StationList[100];
=======
    StationClass StationList[100];
>>>>>>> 4884c76 (add derived classes WCP, SCP, NP Passengers and WCB, MB.)
    Queue<BusClass*> CheckUpQueueMbus;
    Queue<BusClass*> CheckUpQueueWCbus;
    Queue<BusClass*> MovingBusMbus;
    Queue<BusClass*> MovingBusWCBus;

public:
};

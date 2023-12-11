#include <iostream>
#include "PassengerClass.h"
#include "EventClass.h"
#include "StationClass.h"
#include "BusClass.h"
#include "FileHandler.h"
#include "UiClass.h"

using namespace std;

int main() {
    FileHandler fileHandler("../random_file.txt");
    CompanyClass* company = new CompanyClass(fileHandler.getNumStations(), TimeClass(0,fileHandler.getTimeBetweenStations()),
                                             fileHandler.getWBusCount(), fileHandler.getMBusCount(),
                                             fileHandler.getWBusCapacity(), fileHandler.getMBusCapacity(),
                                             fileHandler.getJ(), fileHandler.getC_WBus(), fileHandler.getC_MBus());
    TimeClass time(4, 0);
    int timecounter;
    while(time!=TimeClass(22,00)) {
        time.tick();
        timecounter++;

        processEvent("../random_file.txt", time, company);
        {
            if (timecounter % 60 == 0) {
                company->moveBus(time);
                cout << "Time: " << time << endl;
                cout << "Number of passengers waiting: " << company->getStation(0).getNPpassengers().getLength()
                     << endl;
                cout << "Number of passengers on bus: " << company->getMovingBus().getLength() << endl;
                cout << "Number of buses moving: " << company->getMovingBus().getLength() << endl;
                cout << "Number of buses at station: " << company->getStation(0).getBusQueue().getLength() << endl;

            }
        }
    }
}

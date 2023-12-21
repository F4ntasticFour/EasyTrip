#include <iostream>
#include "PassengerClass.h"
#include "EventClass.h"
#include "StationClass.h"
#include "FileHandler.h"
#include<unistd.h>
unsigned int microsecond = 1000000;

using namespace std;

int main() {
    FileHandler fileHandler("../random_file.txt");
    CompanyClass* company = new CompanyClass(fileHandler.getNumStations(),
                                             TimeClass(0, fileHandler.getTimeBetweenStations()),
                                             fileHandler.getWBusCount(), fileHandler.getMBusCount(),
                                             fileHandler.getWBusCapacity(), fileHandler.getMBusCapacity(),
                                             fileHandler.getJ(), fileHandler.getC_WBus(), fileHandler.getC_MBus());
    TimeClass time(4, 0);
    Queue<std::vector<std::string>> eventQueue = fileHandler.processEventLines();
    int timecounter = 0;


    while (time != TimeClass(7, 40)) {
        time.tick();
        usleep(0.1 * microsecond);
        cout << time << endl;
        if (processEvent(time, company, eventQueue)) {
            eventQueue.dequeue();
        }
            while (timecounter == 12){
                for(int i = 0; i < company->getStationCount(); i++){
                    // company->moveBus(company->getStation(i).getFwBus());

                }
                timecounter = 0;
            }
        timecounter++;
    }
    cout << "Station 0: NP: " << company->getStation(0).getCount("NP") << " Sp: " << company->getStation(0).
            getCount("SP") << " WP: " << company->getStation(0).getCount("WP") << endl;

    cout << "Station 1: NP: " << company->getStation(1).getCount("NP") << " Sp: " << company->getStation(1).
            getCount("SP") << " WP: " << company->getStation(1).getCount("WP") << endl;

    cout << "Station 2: NP: " << company->getStation(2).getCount("NP") << " Sp: " << company->getStation(2).
            getCount("SP") << " WP: " << company->getStation(2).getCount("WP") << endl;

    cout << "Station 3: NP: " << company->getStation(3).getCount("NP") << " Sp: " << company->getStation(3).
            getCount("SP") << " WP: " << company->getStation(3).getCount("WP") << endl;

    cout << "Station 4: NP: " << company->getStation(4).getCount("NP") << " Sp: " << company->getStation(4).
            getCount("SP") << " WP: " << company->getStation(4).getCount("WP") << endl;

}



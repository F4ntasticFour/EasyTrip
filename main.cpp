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
    CompanyClass* company = new CompanyClass(fileHandler.getNumStations(), fileHandler.getTimeBetweenStations(),
                                             fileHandler.getWBusCount(), fileHandler.getMBusCount(),
                                             fileHandler.getWBusCapacity(), fileHandler.getMBusCapacity(),
                                             fileHandler.getJ(), fileHandler.getC_WBus(), fileHandler.getC_MBus());
    TimeClass time(4, 0);
    Queue<std::vector<std::string>> eventQueue = fileHandler.processEventLines();

    for (int i = 0; i < 10; i++) {
        cout << eventQueue.frontElement()[0] << endl;
        cout << eventQueue.frontElement()[1] << endl;
        cout << eventQueue.frontElement()[2] << endl;
        cout << eventQueue.frontElement()[3] << endl;
        cout << eventQueue.frontElement()[4] << endl;
        cout << eventQueue.frontElement()[5] << endl;
        cout << eventQueue.frontElement()[6] << endl<<endl;


        eventQueue.dequeue();
    }


    // while (time!=TimeClass(6,00)) {
    //     time.tick();
    //     cout<<time<<endl;
    //     if(processEvent(time, company, eventQueue,fileHandler.getNumEvents()-1 )) {
    //         eventQueue.dequeue();
    //     }
    // }
    // cout<<"Station 0: NP: "<<company->getStation(0).getCount("WP")<<" Sp: "<<company->getStation(0).getCount("SP")<<" WP: "<<company->getStation(0).getCount("WP")<<endl;
    // cout<<"Station 1: NP: "<<company->getStation(1).getCount("WP")<<" Sp: "<<company->getStation(1).getCount("SP")<<" WP: "<<company->getStation(1).getCount("WP")<<endl;
    // cout<<"Station 2: NP: "<<company->getStation(2).getCount("WP")<<" Sp: "<<company->getStation(2).getCount("SP")<<" WP: "<<company->getStation(2).getCount("WP")<<endl;
    // cout<<"Station 3: NP: "<<company->getStation(3).getCount("WP")<<" Sp: "<<company->getStation(3).getCount("SP")<<" WP: "<<company->getStation(3).getCount("WP")<<endl;
    // cout<<"Station 4: NP: "<<company->getStation(4).getCount("WP")<<" Sp: "<<company->getStation(4).getCount("SP")<<" WP: "<<company->getStation(4).getCount("WP")<<endl;
    // cout<<"Station 5: NP: "<<company->getStation(5).getCount("WP")<<" Sp: "<<company->getStation(5).getCount("SP")<<" WP: "<<company->getStation(5).getCount("WP")<<endl;
    // cout<<"Station 6: NP: "<<company->getStation(6).getCount("WP")<<" Sp: "<<company->getStation(6).getCount("SP")<<" WP: "<<company->getStation(6).getCount("WP")<<endl;
}

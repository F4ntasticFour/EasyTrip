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
    TimeClass time(0, 0);
    processEvent("../random_file.txt",time, company);
}

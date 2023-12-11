#include <iostream>
#include "PassengerClass.h"
#include "EventClass.h"
#include "StationClass.h"
#include "BusClass.h"
#include "FileHandler.h"
#include "UiClass.h"

using namespace std;

int main() {
    FileHandler file("input.txt");
    CompanyClass* company = new CompanyClass(file.getNumStations(), file.getTimeBetweenStations(), file.getWBusCount(),
                                             file.getMBusCount(), file.getWBusCapacity(), file.getMBusCapacity(),
                                             file.getJ(), file.getC_WBus(), file.getC_MBus());
    TimeClass time(0, 0);
    processEvent("../random_file.txt", company);
    return 0;
}

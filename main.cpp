#include <iostream>
#include "PassengerClass.h"
#include "EventClass.h"
#include "StationClass.h"
#include "FileHandler.h"
#include<unistd.h>

using namespace std;

int main() {
    CompanyClass * company;
    company->startSimulation("../random_file.txt");


}

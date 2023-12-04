//
// Created by Safey Elrahman on 04/12/2023.
//

#ifndef EASYTRIP_TIMECLASS_H
#define EASYTRIP_TIMECLASS_H

#include <iostream>

class Time {
private:
    int hours;
    int minutes;

    void normalize();

public:
    Time(int hours = 0, int minutes = 0);

    void addMinutes(int mins);

    void tick();

    friend std::ostream& operator<<(std::ostream& os, const Time& t);
};


#endif //EASYTRIP_TIMECLASS_H

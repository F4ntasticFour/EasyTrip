//
// Created by Safey Elrahman on 04/12/2023.
//

#include "TimeClass.h"
#include <iomanip>

void Time::normalize() {
    while (minutes >= 60) {
        minutes -= 60;
        hours++;
    }
    hours %= 24;
}

Time::Time(int h, int m) : hours(h), minutes(m) {
    normalize();
}

void Time::addMinutes(int mins) {
    minutes += mins;
    normalize();
}

void Time::tick() {
    addMinutes(5);  // Every tick adds 10 minutes
}

std::ostream& operator<<(std::ostream& os, const Time& t) {
    os << std::setfill('0') << std::setw(2) << t.hours << ":"
       << std::setfill('0') << std::setw(2) << t.minutes;
    return os;
}


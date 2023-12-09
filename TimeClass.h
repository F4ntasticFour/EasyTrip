// timeclass.h

#ifndef EASYTRIP_TIMECLASS_H
#define EASYTRIP_TIMECLASS_H

#include <iostream>

class TimeClass {
private:
    int hours;
    int minutes;

    void normalize();

public:
    TimeClass(int hours = 0, int minutes = 0);

    void addMinutes(int mins);

    void tick();

    friend std::ostream& operator<<(std::ostream& os, const TimeClass& t);
    friend bool operator<(const TimeClass& lhs, const TimeClass& rhs);
    friend bool operator>(const TimeClass& lhs, const TimeClass& rhs);
    friend bool operator==(const TimeClass& lhs, const TimeClass& rhs);
    friend bool operator!=(const TimeClass& lhs, const TimeClass& rhs);
    friend TimeClass operator+(const TimeClass& lhs, const TimeClass& rhs);
    friend TimeClass operator-(const TimeClass& lhs, const TimeClass& rhs);
    TimeClass& operator=(TimeClass& rhs); // Corrected here
};

#endif //EASYTRIP_TIMECLASS_H

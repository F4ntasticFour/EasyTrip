// timeclass.h

#ifndef EASYTRIP_TIMECLASS_H
#define EASYTRIP_TIMECLASS_H

#include <iostream>

class TimeClass {
public:
    int hours;

    int minutes;

    void normalize();

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

    // Inside the TimeClass declaration
    TimeClass& operator=(const TimeClass& rhs);

    // Inside the TimeClass declaration
    TimeClass operator*(int multiplier) const;
    // Inside the TimeClass declaration
    TimeClass operator/(int divisor) const;

};


#endif //EASYTRIP_TIMECLASS_H

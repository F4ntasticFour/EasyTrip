// timeclass.cpp

#include "TimeClass.h"
#include <iostream>
#include <iomanip>

// Constructor
TimeClass::TimeClass(int hours, int minutes) : hours(hours), minutes(minutes) {
    normalize();
}

// Private member function to normalize time
void TimeClass::normalize() {
    hours += minutes / 60;
    minutes %= 60;
    hours %= 24;
}

// Public member function to add minutes to the time
void TimeClass::addMinutes(int mins) {
    minutes += mins;
    normalize();
}

// Public member function to increment time by one minute
void TimeClass::tick() {
    addMinutes(1);
}

// Overloaded assignment operator

// Overloaded stream insertion operator
std::ostream& operator<<(std::ostream& os, const TimeClass& t) {
    os << std::setfill('0') << std::setw(2) << t.hours << ":"
       << std::setfill('0') << std::setw(2) << t.minutes;
    return os;
}

// Overloaded less-than operator
bool operator<(const TimeClass& lhs, const TimeClass& rhs) {
    if (lhs.hours < rhs.hours) {
        return true;
    }if (lhs.hours == rhs.hours && lhs.minutes < rhs.minutes) {
        return true;
    }
    return false;
}

// Overloaded greater-than operator
bool operator>(const TimeClass& lhs, const TimeClass& rhs) {
    if (lhs.hours > rhs.hours) {
        return true;
    } else if (lhs.hours == rhs.hours && lhs.minutes > rhs.minutes) {
        return true;
    }
    return false;
}

// Overloaded equality operator
bool operator==(const TimeClass& lhs, const TimeClass& rhs) {
    return (lhs.hours == rhs.hours && lhs.minutes == rhs.minutes);
}

// Overloaded inequality operator
bool operator!=(const TimeClass& lhs, const TimeClass& rhs) {
    return !(lhs == rhs);
}

// Overloaded addition operator
TimeClass operator+(const TimeClass& lhs, const TimeClass& rhs) {
    TimeClass temp(lhs.hours + rhs.hours, lhs.minutes + rhs.minutes);
    temp.normalize();
    return temp;
}

// Overloaded subtraction operator
TimeClass operator-(const TimeClass& lhs, const TimeClass& rhs) {
    TimeClass temp(lhs.hours - rhs.hours, abs(lhs.minutes - rhs.minutes));
    temp.normalize();
    return temp;
}
// Definition for overloaded multiplication operator
TimeClass TimeClass::operator*(int multiplier) const {
    TimeClass temp(hours * multiplier, minutes * multiplier);
    temp.normalize();
    return temp;
}
// Definition for overloaded assignment operator
TimeClass& TimeClass::operator=(const TimeClass& rhs) {
    if (this != &rhs) {
        hours = rhs.hours;
        minutes = rhs.minutes;
        normalize();
    }
    return *this;
}

// Overloaded division operator
TimeClass TimeClass::operator/(int divisor) const {
    if (divisor == 0) {
        throw std::invalid_argument("Cannot divide by zero");
    }
    int totalMinutes = hours * 60 + minutes;
    totalMinutes /= divisor;
    TimeClass temp(abs(totalMinutes / 60), abs(totalMinutes % 60));
    temp.normalize();
    return temp;
}




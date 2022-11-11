/*
Name: Michael Shen
Instructor: Genadiy Maryash
Course: CSCI 135
Lab: 10A
*/

#include <iostream>

class Time {
    public:
        int h;
        int m;
};

int minutesSinceMidnight(Time time) {
    return time.h * 60 + time.m;
}

int minutesUntil(Time earlier, Time later) {
    int minutes = (later.h - earlier.h) * 60;
    if (later.m < earlier.m) {
        minutes += 60 - earlier.m + later.m;
        minutes -= 60;
    } else {
        minutes += later.m - earlier.m;
    }
    return minutes;
}

Time addMinutes(Time time0, int min) {  
    int remaining = (min + time0.m) % 60;
    time0.h += (min + time0.m) / 60;
    time0.m = remaining;
    return time0;
}

int main() {
    Time t1 = {10, 30}, t2 = {7, 20};
    std::cout << minutesUntil(t1, t2);
    return 0;
}
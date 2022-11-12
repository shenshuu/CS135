/*
Name: Michael Shen
Instructor: Genadiy Maryash
Course: CSCI 135
Lab: 10A
*/

#include <iostream>
#include <string>

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

enum Genre {COMEDY, ACTION, DRAMA, ROMANCE, THRILLER};

class Movie { 
public: 
    std::string title;
    Genre genre;     // only one genre per movie
    int duration;    // in minutes
};

class TimeSlot { 
public: 
    Movie movie;     // what movie
    Time startTime;  // when it starts
};

void printTimeSlot(TimeSlot ts) {
    std::string time_slot = ts.movie.title + " ";
    std::string g;
    switch (ts.movie.genre) {
        case ACTION   : g = "ACTION"; break;
        case COMEDY   : g = "COMEDY"; break;
        case DRAMA    : g = "DRAMA"; break;
        case ROMANCE  : g = "ROMANCE"; break;
        case THRILLER : g = "THRILLER"; break;
    }
    time_slot += g + " ";
    time_slot += "(" + std::to_string(ts.movie.duration) + " min)" + " ";
    time_slot += '[';
    time_slot += "starts at " + std::to_string(ts.startTime.h) + ":";
    time_slot += std::to_string(ts.startTime.m) + ", ";
    Time end_time = addMinutes(ts.startTime, ts.movie.duration);
    time_slot += "ends by " + std::to_string(end_time.h) + ":";
    time_slot += std::to_string(end_time.m) + "]";
    std::cout << time_slot << "\n";
}

TimeSlot scheduleAfter(TimeSlot ts, Movie nextMovie) {
    TimeSlot t = {
        {nextMovie.title, nextMovie.genre, nextMovie.duration},
        addMinutes(ts.startTime, ts.movie.duration)
        };
    return t;
}

int main() {
    Time t1 = {9, 15}, t2 = {12, 15}, t3 = {16, 45}, t4 = {17, 0}, t5 = {17, 1};
    Movie movie1 = {"Back to the Future", COMEDY, 116};
    Movie movie2 = {"Black Panther", ACTION, 134};
    Movie movie3 = {"Black Panther", ACTION, 134};
    Movie movie4 = {"Black Panther", ACTION, 134};
    Movie movie5 = {"Black Panther", ACTION, 134};
    TimeSlot morning = {movie1, t1};  
    TimeSlot noon = {movie2, t2};
    TimeSlot evening1 = {movie3, t3};
    TimeSlot evening2 = {movie4, t4};
    TimeSlot evening3 = {movie5, t5};
    // std::cout << minutesUntil(t1, t2);
    printTimeSlot(morning);
    printTimeSlot(noon);
    printTimeSlot(evening1);
    printTimeSlot(evening2);
    printTimeSlot(evening3);
    return 0;
}
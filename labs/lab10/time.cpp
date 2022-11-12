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

void printMovie(Movie mv){
    std::string g;
    switch (mv.genre) {
        case ACTION   : g = "ACTION"; break;
        case COMEDY   : g = "COMEDY"; break;
        case DRAMA    : g = "DRAMA";  break;
        case ROMANCE  : g = "ROMANCE"; break;
        case THRILLER : g = "THRILLER"; break;
    }
    std::cout << mv.title << " " << g << " (" << mv.duration << " min)";
}

void printTimeSlot(TimeSlot ts) {
    printMovie(ts.movie);
    std::cout << " [starts at " << ts.startTime.h << ":" << ts.startTime.m;
    Time end_time = addMinutes(ts.startTime, ts.movie.duration);
    std::cout << ", ends by " << end_time.h << ":" << end_time.m << "]";
}

TimeSlot scheduleAfter(TimeSlot ts, Movie nextMovie) {
    TimeSlot t = {
        {nextMovie.title, nextMovie.genre, nextMovie.duration},
        addMinutes(ts.startTime, ts.movie.duration)
        };
    return t;
}

bool timeOverlap(TimeSlot ts1, TimeSlot ts2) {
    TimeSlot earlier, later;
    if (ts1.startTime.h < ts2.startTime.h) {
        earlier = ts1;
        later = ts2;
    } else if (ts1.startTime.h == ts2.startTime.h && ts1.startTime.m < ts2.startTime.m) {
        earlier = ts1;
        later = ts2;
    } else {
        earlier = ts2;
        later = ts1;
    }
    Time start = addMinutes(earlier.startTime, earlier.movie.duration);
    if (start.h > later.startTime.h) {
        return true;
    } else if (start.h == later.startTime.h && start.m > later.startTime.m) {
        return true;
    } else {
        return false;
    }
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
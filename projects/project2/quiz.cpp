/* 
Name: Michael Shen 
Course: CSCI 135 
Instructor: Genadiy Maryash
Quiz: 10
*/

#include <iostream>
using namespace std;

string month[12] = {
    "Jan","Feb","Mar","Apr","May","Jun",
    "Jul","Aug","Sep","Oct","Nov","Dec"
};

class Date {
    public:
        int month;
        int day;
        int year;
};

string formatDate(Date *d) {
    string date = "";
    date += month[d->month-1];
    date += " " + to_string(d->day) + ", ";
    date += to_string(d->year);
    return date;
}

int main() {
    Date d;
    d.month = 10;
    d.day = 12;
    d.year = 2022;
    cout << formatDate(&d) << endl; 
    return 0;
}
/* 
Name: Michael Shen 
Instructor: Genadiy Maryash
Course: CSCI 135
HW: E7.16
*/

#include <iostream>
#include <cmath>
using namespace std;

struct Point {
    double x;
    double y;
};

double distance(Point a, Point b) {
    return sqrt((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y));
}

int main() {
    Point a = {0.0, 0.0};
    Point b = {1.0, 1.0};
    cout << distance(a, b);
    return 0;
}
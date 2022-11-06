/*
Name: Michael Shen 
Instructor: Genadiy Maryash
Course: CSCI 135
Lab: 9A
*/

#include <iostream>
#include <cmath>
using namespace std;

class Coord3D {
    public:
        double x, y, z;
};

double length(Coord3D *p) {
    return sqrt((*p).x*(*p).x + (*p).y*(*p).y + (*p).z*(*p).z);
}

Coord3D* farthestFromOrigin(Coord3D *p, Coord3D *q) {
    return length(p) > length(q) ? p : q;
}

void move(Coord3D *ppos, Coord3D *pvel, double dt) {
    (*ppos).x += (*pvel).x * dt;
    (*ppos).y += (*pvel).y * dt;
    (*ppos).z += (*pvel).z * dt;
}

int main() {    
    Coord3D pos = {0, 0, 100.0};
    Coord3D vel = {1, -5, 0.2};

    move(&pos, &vel, 2.0); // object pos gets changed
    cout << pos.x << " " << pos.y << " " << pos.z << endl;
    // prints: 2 -10 100.4
    return 0;
}
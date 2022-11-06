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

Coord3D* fartherFromOrigin(Coord3D *p, Coord3D *q) {
    return length(p) > length(q) ? p : q;
}

void move(Coord3D *ppos, Coord3D *pvel, double dt) {
    (*ppos).x += (*pvel).x * dt;
    (*ppos).y += (*pvel).y * dt;
    (*ppos).z += (*pvel).z * dt;
}

Coord3D* createCoord3D(double x, double y, double z) {
    Coord3D *p = new Coord3D;
    (*p).x = x;
    (*p).y = y;
    (*p).z = z;
    return p;
}

void deleteCoord3D(Coord3D *p) {
    delete p;
    p = nullptr;
}

int main() {    
    Coord3D pointP = {10, 20, 30};
    Coord3D pointQ = {-20, 21, -22};

    cout << "Address of P: " << &pointP << endl;
    cout << "Address of Q: " << &pointQ << endl << endl;

    Coord3D * ans = fartherFromOrigin(&pointP, &pointQ);
   
    cout << "ans = " << ans << endl;
    return 0;
}
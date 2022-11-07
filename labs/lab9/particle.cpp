/* 
Name: Michael Shen
Instructor: Genadiy Maryash
Course: CSCI 135 
Lab: 9F (Bonus)
*/

#include <iostream>
using namespace std;

class Particle {
    public:
        double x, y, z, vx, vy, vz;
};

class Coord3D {
    public:
        double x, y, z;
};

Particle* createParticle(double x, double y, double z, double vx, double vy, double vz) {
    Particle *p = new Particle;
    (*p).x = x;
    (*p).y = y;
    (*p).z = z;
    (*p).vx = vx;
    (*p).vy = vy;
    (*p).vz = vz;
    return p;
}

void setVelocity(Particle *p, double vx, double vy, double vz) {
    (*p).vx = vx;
    (*p).vy = vy;
    (*p).vz = vz;
}

Coord3D getPosition(Particle *p) {
    Coord3D coord = {(*p).x, (*p).y, (*p).z};
    return coord;
}

void move(Particle *p, double dt) {
    (*p).x += (*p).vx * dt;
    (*p).y += (*p).vy * dt;
    (*p).z += (*p).vz * dt;
}

void deleteParticle(Particle *p) {
    delete p;
    p = nullptr;
}

int main() {
     // make new particle
    Particle *p = createParticle(1.0, 1.5, 2.0, 0.1, 0.2, 0.3);
    double time = 0.0;
    double dt = 0.1;
    while(time < 3.0) {
        // update its velocity
        setVelocity(p, 10.0 * time, 0.3, 0.1);

        // move the particle
        move(p, dt);
        time += dt;

        // reporting its coordinates
        cout << "Time: " << time << " \t";
        cout << "Position: "
             << getPosition(p).x << ", "
             << getPosition(p).y << ", "
             << getPosition(p).z << endl;
    }
    // remove the particle, deallocating its memory
    deleteParticle(p);
    return 0;
}
/*
Name: Michael Shen 
Instructor: Genadiy Maryash
Course: CSCI 135
Lab: 9A
*/

#include <iostream>
#include <cmath>
using namespace std;

#include <iostream>
using namespace std;

string * createAPoemDynamically() {
    string *p = new string;
    *p = "Roses are red, violets are blue";
    return p;
}

int main() {
    while(true) {
        string *p;
        p = createAPoemDynamically();
        delete p;
        p = nullptr;
    }
}
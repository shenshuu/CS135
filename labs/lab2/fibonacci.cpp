/*
Author: Michael Shen
Course: CSCI-135
Instructor: Gennadiy Maryash 
Assignment: Lab2A

Checks for valid input
*/

#include <iostream>
using namespace std;

int main() {
    int fibs[60];
    fibs[0] = 0;
    fibs[1] = 1;
    cout << 0 << endl;
    cout << 1 << endl;
    for (int i = 2; i < 59; i++) {
        fibs[i] = fibs[i-1] + fibs[i-2];
        cout << fibs[i] << endl;
    }
    return 0;
}
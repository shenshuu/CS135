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
    int myData[10];
    for (int i = 0; i < 10; i++) {
        myData[i] = 1;
        cout << myData[i] << " ";
    }
    cout << "\n";
    int v, i = 0;
    while (0 <= i && i < 10) {
        cout << "Enter index: \n";
        cin >> i;
        cout << "Enter value: \n";
        cin >> v;
        if (0 <= i && i < 10) {
            myData[i] = v;
            for (int j = 0; j < 10; j++) {
                cout << myData[j] << " ";
            }
            cout << "\n";
        }
    }
    cout << "Index out of range. Exit.";
    return 0;
}
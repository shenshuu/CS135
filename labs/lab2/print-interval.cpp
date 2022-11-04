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
    int l, r;
    cout << "Please enter L: \n";
    cin >> l;
    cout << "Please enter R: \n";
    cin >> r;
    for (int i = l; i < r; i++) {
        cout << i << " ";
    }
    return 0;
}
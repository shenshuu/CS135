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
    cout << "Please enter an integer \n";
    int n = 0;
    cin >> n;
    while (!(0 < n && n < 100)) {
        cout << "Please re-enter: \n";
        cin >> n;
    }
    cout << "Number squared is " << n * n << endl;
    return 0;
}
/*
Name: Michael Shen 
Course: CSCI 135 
Instructor: Gennadiy Maryash
Project: 1
Task: A
*/

#include <iostream>
using namespace std;

int main() {
    char c;

    while (cin >> c) {
        if (c == 'U') {
            cout << "Up\n";
        } else if (c == 'D') {
            cout << "Down\n";
        } else if (c == 'L') {
            cout << "Left\n";
        } else if (c == 'R') {
            cout << "Right\n";
        }
    }

    return 0;
}
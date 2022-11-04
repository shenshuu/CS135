/*
Name: Michael Shen 
Course: CSCI 135 
Instructor: Gennadiy Maryash
Task: 6A
*/

#include <iostream>
using namespace std;

int main() {
    string str;
    getline(cin, str);
    for (char c: str) {
        cout << c << " " << (int) c << endl;
    }
    return 0;
}
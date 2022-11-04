/*
Name: Michael Shen 
Instructor: Gennadiy Maryash 
Course: CSCI 135
*/

#include <iostream>
using namespace std;
int main() {
    int size;
    cout << "Input size: \n";
    cin >> size;

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (j == i || j == (size - i - 1)) {
                cout << "*";
            } else {
                cout << " ";
            }
        }
        cout << "\n";
    }
    return 0;
}

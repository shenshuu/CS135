/*
Name: Michael Shen 
Instructor: Gennadiy Maryash 
Course: CSCI 135
*/

#include <iostream>
using namespace std;
int main() {
    int side;
    cout << "Input side: \n";
    cin >> side;
    
    for (int i = 0; i < side; i++) {
        for (int k = 0; k < i; k++) cout << " ";
        for (int j = 0; j < side - i; j++) {
            cout << "*";
        }
        cout << "\n";
    }
    return 0;
}

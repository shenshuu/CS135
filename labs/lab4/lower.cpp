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
        for (int j = 0; j <= i; j++) {
            cout << "*";
        }
        cout << "\n";
    }
    return 0;
}

/*
Name: Michael Shen 
Instructor: Gennadiy Maryash 
Course: CSCI 135
Lab: 4G
File: trapezoid.cpp
another comment
*/

#include <iostream>
using namespace std;
int main() {
    int width, height;
    cout << "Input width: \n";
    cin >> width;
    cout << "Input height: \n";
    cin >> height;

    if (width - (height * 2) + 2 >= 1) {
        for (int h = 0; h < height; h++) {
            for (int space = 0; space < h; space++) {
                cout << " ";
            }
            for (int w = 0; w < width-(2*h); w++) {
                cout << "*";
            }
            cout << "\n";
        }
    } else {
        cout << "Impossible shape";
    }

    return 0;
}

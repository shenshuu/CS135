/*
Name: Michael Shen 
Instructor: Gennadiy Maryash 
Course: CSCI 135
*/

#include <iostream>
using namespace std;
int main() {
    int width, height;
    cout << "Input width: \n";
    cin >> width;
    cout << "Input height: \n";
    cin >> height;

    for (int h = 0; h < height; h++) {
        for (int w = 0; w < width; w++) {
	    cout << "*";
	}
	cout << "\n";
    }
    return 0;
}

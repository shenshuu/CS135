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
    
    bool white = false;
    string res = "";
    for (int i = 0; i < height; ++i) {
        for (int j = 0, c = '*'; j < width; ++j, c = '*') {
            if (((j / 3) & 1) ^ ((i / 3) & 1))
                c = ' ';

            res += (char)c;
        }

        res += '\n';
    }
    cout << res;
    return 0;
}

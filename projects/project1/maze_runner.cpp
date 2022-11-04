/*
Name: Michael Shen 
Course: CSCI 135 
Instructor: Gennadiy Maryash
Project: 1
Task: 3
*/

#include <iostream>
using namespace std;

int main() {

    int maze[6][6] = {
        1,0,1,1,1,1,
        1,0,0,0,1,1,
        1,0,1,0,0,1,
        1,0,1,0,1,1,
        1,0,0,0,0,0,
        1,1,1,1,1,1
    };

    int row = {0}, col = {1};
    string str;

    while (cin >> str) {
        for (char c: str) {
            if (row < 5 && c == 'D' && maze[row+1][col] == 0) {
                row += 1;
            } else if (row > 0 && c == 'U' && maze[row-1][col] == 0) {
                row -= 1;
            } else if (col < 5 && c == 'R' && maze[row][col+1] == 0) {
                col += 1;
            } else if (col > 0 && c == 'L' && maze[row][col-1] == 0) {
                col -= 1;
            }
        }
    }

    if (row == 4 && col == 5) {
        cout << "You got out of the maze.\n";
    } else {
        cout << "You are stuck in the maze.\n";
    }

    return 0;
}
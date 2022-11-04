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

    char maze[10][10];

    int row, col;
    int start_row, start_col;
    int end_row, end_col;
    char c;

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            cin >> c;
            maze[i][j] = c;
        }
    }

    cin >> start_row;
    cin >> start_col;
    cin >> end_row;
    cin >> end_col;
    cin >> c;

    row = start_row;
    col = start_col;

    while (cin >> c) {
        if (c == ';') {
            if (row == end_row && col == end_col) {
                cout << "You got out of the maze.\n";
            } else {
                cout << "You are stuck in the maze.\n";
            }
            row = start_row, col = start_col;
        } else if (row < 10 && c == 'D' && maze[row+1][col] == '0') {
            row += 1;
        } else if (row > 0 && c == 'U' && maze[row-1][col] == '0') {
            row -= 1;
        } else if (col < 10 && c == 'R' && maze[row][col+1] == '0') {
            col += 1;
        } else if (col > 0 && c == 'L' && maze[row][col-1] == '0') {
            col -= 1;
        }
    }

    return 0;
}


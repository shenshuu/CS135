/*
Name: Michael Shen 
Instructor: Genadiy Maryash
Course: CS-135
Lab: 7A
*/

#include <iostream>
#include <string> 
#include <cctype>
using namespace std;

string removeLeadingSpaces(string line) {
    
    string new_line = "";
    int i = 0;

    while (isspace(line[i])) i += 1;
    while (i < line.length()) {
        new_line += line[i];
        i += 1;
    }

    return new_line;
}

int main() {
    string line;
    while (getline(cin, line)) {
        cout << removeLeadingSpaces(line) << endl;
    }
    return 0;
}
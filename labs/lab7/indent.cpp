/*
Name: Michael Shen 
Instructor: Genadiy Maryash
Course: CS-135
Lab: 7B
*/

#include <iostream>
#include <string>
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

int countChar(string line, char c) {
    int count = 0;
    for (char chr: line) {
        if (chr == c) count += 1;
    }
    return count;
}

int main() {
    string line;
    int indentations = 0;
    getline(cin, line);
    cout << removeLeadingSpaces(line) << endl;

    while (getline(cin, line)) {
        indentations -= countChar(line, '}');
        indentations += countChar(line, '{');
        for (int i = 0; i < indentations; i++) cout << '\t';
        cout << removeLeadingSpaces(line) << endl;
    }
    return 0;
}
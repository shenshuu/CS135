/* 
Name: Michael Shen
Instructor: Genadiy Maryash
Course: CSCI 135 
Project: 2A
*/

#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
using namespace std;

int main() {
    
    ifstream input;
    input.open("input.txt");
    ofstream output;

    string line, file_name, width;
    getline(input, line);
    int max_width, i = 0;

    while (line[i] != ';') width += line[i++];
    max_width = stoi(width);
    i++;
    while (line[i] != ';') file_name += line[i++];
    output.open(file_name);

    int line_width = max_width;
    string word;

    while (getline(input, line)) {
        cout << line_width << endl;
        if (line.length() == 0) {
            line_width = max_width;
            output << "\n\n";
        } else if (line.length() <= line_width) {
            line_width = max_width;
            output << line << '\n';
        } else {
            i = 0;
            word = "";
            while (i <= line.length()) {
                if (line_width - word.length() <= 0) {
                    line_width = max_width;
                    output << '\n';
                }
                if (isspace(line[i]) || i == line.length()) {
                    output << word << " ";
                    line_width -= word.length() + 1;
                    word = "";
                } else {
                    word += line[i];
                }
                i++;
            }
        }
    }
    return 0;
}
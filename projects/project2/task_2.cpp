/* 
Name: Michael Shen
Instructor: Genadiy Maryash
Course: CSCI 135 
Project: 2B
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
    string body_just, head_just;
    getline(input, line);

    int max_width, count = 0, i = 0;
    for (int j = 0; j < line.length(); j++) {
        if (line[j] == ';') count++;
    }

    while (line[i] != ';') width += line[i++];
    max_width = stoi(width);
    i++;

    while (count > 2) {
        while (line[i] != ';') body_just += line[i++];
        i++;
        count--;
        if (count <= 2) break;
        while (line[i] != ';') head_just += line[i++];
        i++;
        count--;
    }

    while (line[i] != ';') file_name += line[i++];
    output.open(file_name);

    int line_width = max_width;
    string word;

    while (getline(input, line)) {
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
                    output << word;
                    if (i != line.length()) {
                        output << " "; 
                        line_width--;
                    }
                    line_width -= word.length();
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
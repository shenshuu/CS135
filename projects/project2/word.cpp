/* 
Name: Michael Shen
Instructor: Genadiy Maryash
Course: CSCI 135 
Project: 2A
*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <iomanip>

using namespace std;

int main() {
    
    ifstream input;
    string input_file;
    ofstream output;

    cout << "Enter the input filename: ";
    cin >> input_file;
    input.open(input_file);

    string line, new_line = "", file_name = "", width = "";
    getline(input, line);
    
    int max_width, i = 0;
    while (line[i] != ';') width += line[i++];
    max_width = stoi(width);
    i++;
    while (line[i] != ';') file_name += line[i++];
    output.open(file_name);

    string word;
    
    while (getline(input, line)) {
        // case when we encounter the empty line 
        if (line.length() == 0 || line.length() < max_width) {
            if (new_line.length() > 0) {
                output << new_line << setw(max_width - new_line.length()) << "\n";
                new_line = "";
            }
            if (line.length() > 0) {
                output << line << setw(max_width - line.length()) << "\n";
            }
        } else {
            istringstream str(line);
            
            while (str >> word) {
                if (new_line.length() == 0) {
                    new_line = word;
                } else {
                    if (new_line.length() + word.length() + 1 < max_width) {
                        new_line += " " + word;
                    } else {
                        output << new_line << setw(max_width - new_line.length()) << "\n";
                        new_line = word;
                    }
                } 
            }
        }
        if (line.length() == 0) output << "\n";
    }
    if (new_line.length() > 0) {
        output << new_line << setw(max_width - new_line.length()) << "\n";
    }
    output.close();
    input.close();
    return 0;
}
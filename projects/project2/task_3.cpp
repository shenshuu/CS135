/* 
Name: Michael Shen
Instructor: Genadiy Maryash
Course: CSCI 135 
Project: 2C
*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>

using namespace std;

// centers text 
string center_text(string text, int max_width) {
    string centered = "";
    int spaces_needed = (max_width - text.length()) / 2;
    for (int i = 0; i < spaces_needed; i++) centered += " ";
    centered += text;
    for (int i = 0; i < spaces_needed; i++) centered += " ";
    return centered;
}

// tests if all characters in a string are capitalized 
bool all_caps(string str) {
    string copy = str;
    transform(copy.begin(), copy.end(),copy.begin(), ::toupper);
    return str == copy;
}

// writes to output file 
void write(ofstream& output, string justification, string new_line, int max_width) {
    if (justification == "right") {
        (all_caps(new_line)) ? max_width -= 2 : max_width -= 1;
        output << setw(max_width) << new_line << "\n";
    } else if (justification == "center") {
        (all_caps(new_line)) ? max_width -= 2 : max_width -= 1;
        output << center_text(new_line, max_width) << "\n";  
    } else {
        output << new_line << setw(max_width - new_line.length() - 1) << "\n";
    }
}

// separates a string into segments depending on the delimiter 
vector<string> split(string str, char delimiter=' ') {
    vector<string> words;
    string word = "";

    for (int i = 0; i < str.length(); i++) {
        if (str[i] == delimiter || i == str.length()-1) {
            if (i == str.length()-1) word += str[i];
            words.push_back(word);
            word = "";
        } else {
            word += str[i];
        }
    }

    return words;
}


int main() {
    
    ifstream input;
    string input_file;
    ofstream output;

    cout << "Enter the input filename: ";
    cin >> input_file;
    input.open(input_file);

    string line, body_just = "left", head_just = "left";
    bool filled = true, double_spaced = true;
    getline(input, line);
    
    vector<string> text = split(line, ';');
    string file_name = text[text.size()-1];
    file_name.pop_back(); // removes final semicolon from file_name 
    int max_width = stoi(text[0]);
    output.open(file_name);
    
    if (text.size() == 3) {
        body_just = text[1];
        head_just = body_just;
    }

    if (text.size() >= 4) {
        body_just = text[1];
        head_just = text[2];
        file_name = text[3];;
    }

    string word;
    
    string new_line = "", justification = head_just;
    while (getline(input, line)) {
        
        // case when we encounter the empty line 
        if (line.length() == 0|| all_caps(line)) {
            if (new_line.length() > 0) {
                all_caps(new_line) ? justification = head_just : justification = body_just;
                write(output, justification, new_line, max_width);
                new_line = "";
            }
        }

        if (line.length() == 0) {
            output << "\n";
        } else if (all_caps(line)) {
            write(output, head_just, line, max_width+1);
        } else {
            istringstream str(line);
            
            while (str >> word) {
                if (new_line.length() == 0) {
                    new_line = word;
                } else {
                    if (new_line.length() + word.length() + 1 < max_width) {
                        new_line += " " + word;
                    } else {
                        all_caps(new_line) ? justification = head_just : justification = body_just;
                        write(output, justification, new_line, max_width);
                        new_line = word;
                    }
                } 
            }
        }

        if (double_spaced) output << "\n";
    }
    if (new_line.length() > 0) {
        write(output, justification, new_line, max_width);
    }
    output.close();
    input.close();
    return 0;
}
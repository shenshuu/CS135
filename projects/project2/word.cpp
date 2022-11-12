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
        if (all_caps(new_line)) {
            output << "\n";
            max_width -= 2; 
        } else {
            max_width -= 1;
        }
        output << setw(max_width) << new_line << "\n";
    } else if (justification == "center") {
        if (all_caps(new_line)) {
            output << "\n";
            max_width -= 2; 
        } else {
            max_width -= 1;
        }
        output << center_text(new_line, max_width) << "\n";  
    } else {
        output << new_line << setw(max_width - new_line.length() - 1) << "\n";
    }
}


int main() {

    ifstream input;
    ofstream output;

    string line = "", new_line = "";
    string input_file, output_file;
    cout << "Enter the input filename: ";
    cin >> input_file;
    input.open(input_file);

    int max_width;

    string head_just = "left", body_just = "left", option;
    bool filled = false, double_spaced = false;
    getline(input, option, ';');
    max_width = stoi(option);

    getline(input, option, ';');
    if (option == "left" || option == "right" || option == "center" || option == "") {
        (option == "") ? body_just = "left" : head_just = option;
        getline(input, option, ';');
    }
    
    if (option == "left" || option == "right" || option == "center" || option == "") {
        (option == "") ? head_just = body_just : head_just = option;
        getline(input, option, ';');
    }

    if (option == "true") {
        filled = true;
        getline(input, option, ';');
    }

    if (option == "true") {
        double_spaced = true;
        getline(input, option, ';');
    } 

    output.open(option);

    string title, word;
    int i = 0;
    
    string justification = head_just;
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
                if (all_caps(word) && word.length() >= 2 || title.length() > 0 && isdigit(word[0])) {
                    if (title.length() == 0) {
                        title = word;
                    } else {
                        title += " " + word;
                    }
                    continue;
                }
                if (title.length() > 0) {
                    if (double_spaced) output << '\n';
                    write(output, head_just, title, max_width);
                    if (double_spaced) output << '\n' << '\n';
                    title = "";
                }
                if (new_line.length() == 0) {
                    new_line = word;
                } else {
                    if (new_line.length() + word.length() + 1 < max_width) {
                        new_line += " " + word;
                    } else {
                        all_caps(new_line) ? justification = head_just : justification = body_just;
                        if (filled) {
                            if (new_line.length() + 1 < max_width) new_line += " ";
                            i = 0;
                            while (new_line.length() < max_width - 2) {
                                new_line += word[i++];
                            }
                            if (i > 0) new_line += "-"; // we broke a word 
                            write(output, justification, new_line, max_width);
                            if (double_spaced) output << "\n";
                            new_line = "";
                            while (i < word.length()) {
                                new_line += word[i++];
                            }
                        } else {
                            write(output, justification, new_line, max_width);
                            if (double_spaced) output << "\n";
                            new_line = word;
                        }
                    }
                } 
            }
        }
    }
    if (new_line.length() > 0) {
        write(output, justification, new_line, max_width);
    }
    output.close();
    input.close();
    return 0;
}
/*
Name: Michael Shen 
Instructor: Genadiy Maryash
Course: CSCI 135
Task: 2C
*/

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <iomanip>
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

void handle_title(ofstream& output, int &max_width, string new_line) {
    if (all_caps(new_line)) {
            output << "\n";
            max_width -= 2; 
        } else {
            max_width -= 1;
        }
}

// writes to output file 
void write(ofstream& output, string justification, string new_line, int max_width) {
    if (justification == "right") {
        handle_title(output, max_width, new_line);
        output << setw(max_width) << new_line << "\n";
    } else if (justification == "center") {
        handle_title(output, max_width, new_line);
        output << center_text(new_line, max_width) << "\n";  
    } else {
        output << new_line << setw(max_width - new_line.length() - 1) << "\n";
    }
}

// handles title 
void handle_title(istringstream &stream, ofstream& output, string head_just, int max_width) {
    string word = "", title = "";
    while (stream >> word) {

        // handle title 
        if (isupper(word[1]) || title.length() > 0 && isdigit(word[0])) {
            if (title.length() == 0) {
                title = word;
            } else {
                title += " " + word;
            }
            continue;
        }

        if (title.length() > 0) {
            write(output, head_just, title, max_width);
            title = "";
        }
    }
}

// handles fill 
void handle_fill(ofstream& output, string &new_line, string word, int max_width, string body_just) {
    int i = 0;
    new_line += " ";
    while (new_line.length() < max_width - 2) {
        new_line += word[i++];
    }
    new_line += "-";
    write(output, body_just, new_line, max_width);
    new_line = "";
    while (i < word.length()) {
        new_line += word[i++];
    }
}


int main() {

    ifstream input;
    ofstream output;

    string line = "", new_line = "";
    string input_file, output_file;
    int max_width;

    cout << "Enter input file: ";
    cin >> input_file;
    input.open(input_file);

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
    getline(input, line);
    getline(input, line);
    string word = "", title = "";

    while(getline(input, line)) {
        if (line.empty()) {
            if (new_line.length() > 0) {
                write(output, body_just, new_line, max_width);
                new_line = "";
            }
            output << '\n';
        } else {
            istringstream stream(line);

            while (stream >> word) {
                if (new_line.empty()) {
                    new_line = word;
                } else if (new_line.length() + word.length() + 2 < max_width) {
                    new_line += " " + word;
                } else {
                    if (filled && new_line.length() + 3 < max_width) {
                        handle_fill(output, new_line, word, max_width, body_just);
                    } else {
                        write(output, body_just, new_line, max_width);
                        new_line = word;
                    }
                }
            }
        } 

    }
    
    input.close();
    output.close();

    return 0;
}

// 60;center;center;true;true;output.txt;

// WHAT IS LOREM IPSUM? Lorem Ipsum is simply dummy text of the printing and typesetting industry. Lorem Ipsum has been the industry’s standard dummy text ever since the 1500s, when an unknown printer took a galley of type and scrambled it to make a type specimen book.

// Speaking of books, I love books. I read and write, sometimes at the same time because why not! Why should I be limited by my measily brain and only do one task at a time? Exactly.

// TITLE 2 Well, thank you for listening. I appreciate you all :)
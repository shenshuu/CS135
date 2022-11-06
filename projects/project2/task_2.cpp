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
#include <vector>
using namespace std;

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
    input.open("input.txt");
    ofstream output;

    string line, body_just = "left", head_just = "left";
    getline(input, line);

    vector<string> data = split(line, ';');
    string file_name = data[data.size()-1];
    file_name.pop_back();
    int max_width = stoi(data[0]);
    output.open(file_name);
    
    if (data.size() == 3) {
        body_just = data[1];
        head_just = body_just;
    }

    if (data.size() == 4) {
        body_just = data[1];
        head_just = data[2];
    }
    
    while (getline(input, line)) {
        
    }

    output.close();
    input.close();
    return 0;
}
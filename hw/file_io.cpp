/* 
Name: Michael Shen
Instructor: Genadiy Maryash
Course: CSCI 135 
HW: 8.1
*/

#include <iostream>
#include <string>
#include <fstream> 
using namespace std;

int main() {
    ofstream out_file;
    out_file.open("hello.txt");
    out_file << "Hello, World!";
    out_file.close();

    ifstream in_file;
    string line;
    in_file.open("hello.txt");
    getline(in_file, line);
    cout << line << endl;
    return 0;
}
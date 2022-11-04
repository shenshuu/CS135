/*
Name: Michael Shen 
Course: CSCI 135 
Instructor: Gennadiy Maryash
Task: 6A
*/

#include <iostream>
using namespace std;

char isLowerCase(char c) {
    return (int) c >= 97 && (int) c <= 122;
}

char isUpperCase(char c) {
    return (int) c >= 65 && (int) c <= 90;
}

// A helper function to shift one character by rshift
char shiftChar(char c, int rshift) {
    string lower = "abcdefghijklmnopqrstuvwxyz";
    string upper = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    if (isLowerCase(c)) {
        return lower[((int) c - 97 + rshift) % 26];
    } else if (isUpperCase(c)) {
        return upper[((int) c - 65 + rshift) % 26];
    }
    return c;
    
}

// Caesar cipher encryption
string encryptCaesar(string plaintext, int rshift) {
    string encrypted = "";
    for (char c: plaintext) {
        encrypted += shiftChar(c, rshift);
    }
    return encrypted;
}

int main() {
    string s;
    int shift;
    cout << "Enter plaintext: \n";
    getline(cin, s);
    cout << "Enter shift: \n";
    cin >> shift;
    cout << encryptCaesar(s, shift);
    return 0;
}
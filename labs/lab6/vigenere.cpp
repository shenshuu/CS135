/*
Name: Michael Shen 
Course: CSCI 135 
Instructor: Gennadiy Maryash
Task: 6C
*/

#include <iostream>
using namespace std;

char isLowerCase(char c) {
    return (int) c >= 97 && (int) c <= 122;
}

char isUpperCase(char c) {
    return (int) c >= 65 && (int) c <= 90;
}

bool isChar(char c) {
    return isLowerCase(c) || isUpperCase(c);
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

// Vigenere cipher encryption
string encryptVigenere(string plaintext, string keyword) {
    string encrypted = "";

    int i = 0;
    for (int j = 0; j < plaintext.length(); j++) {
        encrypted += shiftChar(plaintext[j], ((int) keyword[i % keyword.length()] - 97) % 26);
        if (isChar(plaintext[j])) {
            i++;
        }
    }
    return encrypted;
}

int main() {
    string plaintext, keyword;
    cout << "Enter plaintext: \n";
    getline(cin, plaintext);
    cout << "Enter keyword: \n";
    cin >> keyword;
    cout << encryptVigenere(plaintext, keyword);
    return 0;
}
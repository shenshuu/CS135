/*
Name: Michael Shen 
Course: CSCI 135 
Instructor: Genadiy Maryash 
Lab: 11B
*/

#include <iostream>
#include <vector>
using namespace std;

vector<int> makeVector(int n) {
    vector<int> vect;
    for (int i = 0; i < n; i++) {
        vect.push_back(i);
    }
    return vect;
}
/*
Name: Michael Shen 
Course: CSCI 135 
Instructor: Genadiy Maryash 
Lab: 12B
*/

#include <iostream>
#include <vector>
using namespace std;

vector<int> goodVibes(const vector<int> v) {
    vector<int> positives;
    for (int i = 0; i < v.size(); i++) {
        if (v[i] > 0) positives.push_back(v[i]);
    }
    return positives;
}
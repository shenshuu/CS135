/*
Name: Michael Shen 
Course: CSCI 135 
Instructor: Genadiy Maryash 
Lab: 12B
*/

#include <iostream>
#include <vector>
using namespace std;

vector<int> sumPairWise(vector<int> &v1, vector<int> &v2) {
    int i(0), j(0);
    vector<int> sums;
    while (i < v1.size() && j < v2.size()) {
        sums.push_back(v1[i++] + v2[j++]);
    }
    while (i < v1.size()) sums.push_back(v1[i++]);
    while (j < v2.size()) sums.push_back(v2[j++]);
    return sums;
}
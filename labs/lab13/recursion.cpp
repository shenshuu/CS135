/*
Name: Michael Shen 
Course: CSCI 135 
Instructor: Genadiy Maryash 
Lab: 13A
*/
#include <iostream>
#include <string>
using namespace std;

void printRange(int left, int right) {
    if (left > right) return;
    cout << left << " ";
    printRange(left+1, right);
}

int sumRange(int left, int right) {
    if (left > right) return 0;
    return left + sumRange(left+1, right);
}

int sumArray(int *arr, int size) {
    if (size == 0) return 0;
    return arr[size-1] + sumArray(arr, size-1);
}

bool isAlphanumeric(string s) {
    if (s == "") return true;
    int x = (int) s[0];
    return (x >= 48 && x <= 57 || x >= 65 && x <= 90 || x >= 97 && x <= 122) && isAlphanumeric(s.substr(1));
}
bool parensHelper(string s, int i, int j) {
    if (i > j) return true;
    return s[i] == '(' && s[j] == ')' && parensHelper(s, i+1, j-1);
}
bool nestedParens(string s) {
    return parensHelper(s, 0, s.size()-1);
}

bool helper(int *prices, int target, int i, int size) {
    if (i == size || target < 0) return false;
    if (target == 0) return true;
    return helper(prices, target-prices[i], i+1, size) || helper(prices, target, i+1, size);
}

bool divisible(int *prices, int size) {
    int total = sumArray(prices, size);
    if (total % 2 != 0) return false;
    return helper(prices, total / 2, 0, size);
}

int main() {
    cout << nestedParens("((()))") << endl;      // true (1)
    cout << nestedParens("()") << endl;          // true (1)
    cout << nestedParens("") << endl;            // true (1)

    cout << nestedParens("(((") << endl;         // false (0)
    cout << nestedParens("(()") << endl;         // false (0)
    cout << nestedParens(")(") << endl;          // false (0)
    cout << nestedParens("a(b)c") << endl;       // false (0)
}
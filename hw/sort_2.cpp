/* 
Name: Michael Shen 
Instructor: Genadiy Maryash
Course: CSCI 135
HW: E7.1
*/

#include <iostream>
using namespace std;

void sort2(double *p, double *q) {
    int temp;
    if (*p > *q) {
        temp = *p;
        *p = *q;
        *q = temp;
    }
}

int main() {
    double a = 3.2, b = 5.7;
    sort2(&a, &b);
    cout << a << ", " << b;
    return 0;
}
/* 
Name: Michael Shen 
Instructor: Gennadiy Maryash 
Course: CSCI 135
Task: 5A
*/

#include <iostream>
#include <vector>
using namespace std;

bool isDivisibleBy(int n, int d) {
    return d != 0 && n % d == 0;
}

bool isPrime(int n) {
    for (int i = 2; i <= n / i; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return n > 1;
}

int nextPrime(int n) {
    n += 1;
    while (!isPrime(n)) {
        n += 1;
    }
    return n;
}

int countPrimes(int a, int b) {
    int count = 0;
    while (a <= b) {
        count += isPrime(a) & 1;
        a++;
    }
    return count;
}

bool isTwinPrime(int n) {
    return isPrime(n-2) && isPrime(n) || isPrime(n+2) && isPrime(n);
}

int nextTwinPrime(int n) {
    n += 1;
    while (!isTwinPrime(n)) {
        n += 1;
    }
    return n;
}

int largestTwinPrime(int a, int b) {
    while (a <= b) {
        if (isTwinPrime(b)) {
            return b;
        }
        b--;
    }
    return -1;
}

int main() {
    int a, b;
    cout << "Enter lower bound: \n";
    cin >> a;
    cout << "Enter upper bound: \n";
    cin >> b;
    cout << largestTwinPrime(a, b);
    return 0;
}
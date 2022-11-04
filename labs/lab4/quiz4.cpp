/* 
Name: Michael Shen 
Course: CSCI 135
Instructor: Gennadiy Maryash
*/

#include <iostream> 
#include <fstream>
#include <string>
using namespace std;

int main() {
    ifstream infile("data.txt");
    str a, b;
    while (infile >> a >> b) {
        cout << a << " " << b << endl;
    }
    data.close();
    return 0;
}

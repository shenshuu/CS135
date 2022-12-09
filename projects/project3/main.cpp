/*
Name: Michael Shen 
Course: CSCI 135 
Instructor: Genadiy Maryash 
Project: 3 Task 1 
*/

#include "Bank.hpp"

int main() {
    Bank b;
    std::string acc_num = b.createAccount("Mike", "Shen", "1234");
    b.deposit(1000, acc_num, "1234");
    std::cout << b.withdraw(40, acc_num, "1234");
    std::cout << b.deposit(50, acc_num, "1234");
    std::cout << b.withdraw(961, acc_num, "1234");
    std::cout << b.removeAccount("00000000");
    std::cout << b.getAccountBalance(acc_num, "1234");
    return 0;
}
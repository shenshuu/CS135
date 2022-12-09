/*
Name: Michael Shen 
Course: CSCI 135 
Instructor: Genadiy Maryash 
Project: 3 Task 2
*/

#ifndef BANK_HPP
#define BANK_HPP
#include "Account.hpp"

class Bank {
    private:
        Account accounts[200];
        int numAccounts;

    public:
        Bank();
        std::string createAccount(std::string fname, std::string lname, std::string pin);
        bool removeAccount(std::string acc_number);
        bool withdraw(int amount, std::string acc_number, std::string pin);
        bool deposit(int amount, std::string acc_number, std::string pin);
        int getAccountBalance(std::string acc_number, std::string pin);
};

#endif
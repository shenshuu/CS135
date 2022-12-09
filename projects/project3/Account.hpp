/*
Name: Michael Shen 
Course: CSCI 135 
Instructor: Genadiy Maryash 
Project: 3 Task 1 
*/

#ifndef ACCOUNT_HPP
#define ACCOUNT_HPP
#include <string>
#include <iostream>

class Account {
    public:
        Account(std::string first, std::string last, std::string p);
        Account();
        
        void setFirstName(std::string name);
        void setLastName(std::string name);
        bool setPin(std::string newPin);

        std::string getFirstName();
        std::string getLastName();
        std::string getAccountNumber();
        std::string getPin();
        int getBalance();

        bool transaction(int amount);

    private:
        std::string firstName, lastName;
        std::string accountNumber, pin;
        int balance;
        std::string generateAccountNumber();
};

#endif
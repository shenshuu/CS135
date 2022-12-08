/*
Name: Michael Shen 
Course: CSCI 135 
Instructor: Genadiy Maryash 
Project: 3 Task 1 
*/

#include "Account.hpp"
#include <iostream>

class Account {
    public:
        Account() {
            accountNumber = generateAccountNumber();
            firstName = "anonymous";
            lastName = "anonymous";
            pin = "0000";
            balance = 0;
        }

        void setFirstName(std::string name) {
            firstName = name;
        }

        void setLastName(std::string name) {
            lastName = name;
        }

        bool setPin(std::string newPin) {
            if (pin == "0000") {
                pin = newPin;
                return true;
            } else {
                return false;
            }
        }

        std::string getFirstName() {
            return firstName;
        }

        std::string getLastName() {
            return lastName;
        }

        std::string getAccountNumber() {
            return accountNumber;
        }

        std::string getPin() {
            return pin;
        }

        int getBalance() {
            return balance;
        }

        bool transaction(int amount) {
            if (balance + amount < 0) {
                return false;
            } else {
                balance += amount;
                return true;
            }
        }

    private:
        std::string firstName, lastName;
        std::string accountNumber, pin;
        int balance;

        std::string generateAccountNumber() {
            std::string account = "";
            int digit;
            for (int i = 0; i < 8; i++) {
                digit = rand() % 10;
                account += std::to_string(digit);
            }
            return account;
        }
};

// int main() {
//     Account acc;
//     acc.setFirstName("Mike");
//     std::cout << acc.getFirstName() << std::endl;
//     return 0;
// }
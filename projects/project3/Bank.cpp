/*
Name: Michael Shen 
Course: CSCI 135 
Instructor: Genadiy Maryash 
Project: 3 Task 2
*/

#include "Bank.hpp"

Bank::Bank(): numAccounts(0) {}

std::string Bank::createAccount(std::string fname, std::string lname, std::string pin) {
    if (numAccounts == 200) return "-1";
    std::string result;
    for (int i = 0; i < 200; i++) {
        if (accounts[i].getFirstName() == "anonymous") {
            accounts[i] = Account(fname, lname, pin);
            result = accounts[i].getAccountNumber();
            numAccounts += 1;
            break;
        }
    }
    return result;
}

bool Bank::removeAccount(std::string acc_number) {
    for (int i = 0; i < 200; i++) {
        if (accounts[i].getAccountNumber() == acc_number) {
            accounts[i] = Account("anonymous", "anonymous", "");
            numAccounts--;
            return true;
        }
    }
    return false;
}

bool Bank::withdraw(int amount, std::string acc_number, std::string pin) {
    for (int i = 0; i < 200; i++) {
        if (accounts[i].getAccountNumber() == acc_number && accounts[i].getPin() == pin && accounts[i].transaction(-amount)) {
            return true;
        }
    }
    return false;
}

bool Bank::deposit(int amount, std::string acc_number, std::string pin) {
    for (int i = 0; i < 200; i++) {
        if (accounts[i].getAccountNumber() == acc_number && accounts[i].getPin() == pin && accounts[i].transaction(amount)) {
            return true;
        }
    }
    return false;
}

int Bank::getAccountBalance(std::string acc_number, std::string pin) {
    for (int i = 0; i < 200; i++) {
        if (accounts[i].getAccountNumber() == acc_number && accounts[i].getPin() == pin) {
            return accounts[i].getBalance();
        }
    }
    return -1;
}
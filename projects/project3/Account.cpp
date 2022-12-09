/*
Name: Michael Shen 
Course: CSCI 135 
Instructor: Genadiy Maryash 
Project: 3 Task 1 
*/

#include "Account.hpp"

Account::Account():
    accountNumber(generateAccountNumber()),
    firstName("anonymous"),
    lastName("anonymous"),
    pin("0000"),
    balance(0)
{}

Account::Account(std::string first, std::string last, std::string p):
    accountNumber(generateAccountNumber()),
    firstName(first),
    lastName(last),
    pin(p),
    balance(0)
{}

void Account::setFirstName(std::string name) {
    firstName = name;
}

void Account::setLastName(std::string name) {
    lastName = name;
}

bool Account::setPin(std::string newPin) {
    if (pin.size() == 4) {
        pin = newPin;
        return true;
    } else {
        return false;
    }
}

std::string Account::getFirstName() {
    return firstName;
}

std::string Account::getLastName() {
    return lastName;
}

std::string Account::getAccountNumber() {
    return accountNumber;
}

std::string Account::getPin() {
    return pin;
}

int Account::getBalance() {
    return balance;
}

bool Account::transaction(int amount) {
    if (balance + amount < 0) {
        return false;
    } else {
        balance += amount;
        return true;
    }
}

std::string Account::generateAccountNumber() {
    std::string account = "";
    int digit;
    for (int i = 0; i < 8; i++) {
        digit = rand() % 10;
        account += std::to_string(digit);
    }
    return account;
}
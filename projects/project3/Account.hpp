/*
Name: Michael Shen 
Course: CSCI 135 
Instructor: Genadiy Maryash 
Project: 3 Task 1 
*/

#ifndef ACCOUNT_HPP
#define ACCOUNT_HPP
#include <string>

void setFirstName(std::string name);
void setLastName(std::string name);
std::string getLastName();
std::string getFirstName();

std::string getAccountNumber();
std::string getPin();

bool setPin(std::string newPin);
bool transaction(int amount);
int getBalance();

#endif
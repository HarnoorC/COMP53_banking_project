#ifndef SAVINGSSUBACCOUNT_H
#define SAVINGSSUBACCOUNT_H
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class SavingsSubAccount {
  public:
    SavingsSubAccount(int bal);
    int subAccMenu();
    int deposit();
    int withdraw();
    int getSubAccNum() {return subAccNum;}
    void setSubAccNum(int num) {subAccNum = num;}
    int getBalance() {return balance;}
    void setBalance(int bal) { balance = bal;}
    void printInfo();
  private:
    int balance;
    int subAccNum;
};

#endif
#ifndef CHECKINGSSUBACCOUNT_H
#define CHECKINGSSUBACCOUNT_H
#include <iostream>
#include <string>
#include <vector>
using namespace std;
#include "savingssubaccount.h"

class CheckingsSubAccount : public SavingsSubAccount {
  public:
    CheckingsSubAccount(int bal, int max, string userIn);
    bool getLockStatus() {return locked;}
    void setLockStatus(string userInput);
    void setMaxCapacity(int maxCap) {maxCapacity = maxCap;}
    int getMaxCapacity() {return maxCapacity;}
    void printInfo();
    int subAccMenu();
    int deposit();
    int withdraw();
  private:
    int maxCapacity;
    bool locked = false;
};

#endif
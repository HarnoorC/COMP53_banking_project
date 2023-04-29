#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H
#include "savingssubaccount.h"
#include "checkingssubaccount.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class BankAccount {
  public:
    BankAccount(string firstName, string lastName, string SSN);
    void bankAccMenu();
    void openSavAcc();
    void openCheckAcc();
    void closeSubAcc();
    void printDetailedAccInfo();
    void printBriefAccInfo();
    string getSSN() {return SSN;}
    string getFullName() {return firstName + " " +lastName;}
    int getBankAccNum() {return bankAccNum;}
    void setBankAccNum(int num) {bankAccNum = num;}
    int getAccAggBal() {return accAggBal;}
    void setAccAggBal(int num) {accAggBal = num;}
    vector<SavingsSubAccount> getSavSubAccounts() {return savSubAccounts;}
    vector<CheckingsSubAccount> getCheckingSubAccounts() {return checkingSubAccounts;}
    bool static sortBySavSubAccBal(SavingsSubAccount account1, SavingsSubAccount account2) {
      return account1.getBalance() < account2.getBalance();
    }
    bool static sortByCheckingsSubAccBal(CheckingsSubAccount account1, CheckingsSubAccount account2) {
      return account1.getBalance() < account2.getBalance();
    }
    int accAggBal = 0;
  private:
    int bankAccNum;
    string firstName;
    string lastName;
    string SSN;
    int numSavAcc = 0;
    int numCheckAcc = 0;
    vector<SavingsSubAccount> savSubAccounts;
    vector<CheckingsSubAccount> checkingSubAccounts;
};

#endif
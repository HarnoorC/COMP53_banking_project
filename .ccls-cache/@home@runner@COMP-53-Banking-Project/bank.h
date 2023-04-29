#ifndef BANK_H
#define BANK_H
#include "bankaccount.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct Global1 {
  static int numTotalSavAcc;
  static int numTotalCheckAcc;
};

class Bank {
  public:
      Bank();
      int getNumBankAcc() {return numBankAcc;}
      string getName() {return name;}
      string getAddress() {return address;}
      string getWorkingHours() {return workingHours;}
      void bankMenu();
      void printDetailedInfo();
      void printSortedInfo();
      void openBankAcc();
      void closeBankAcc();
      bool static sortByAccAggBal(BankAccount account1, BankAccount account2) {return account1.getAccAggBal() < account2.getAccAggBal();}
    private:
        string name;
        string address;
        string workingHours;
        vector<BankAccount> accounts;
        int numBankAcc = 0;
        int aggregatedBalance = 0;
        
};




#endif
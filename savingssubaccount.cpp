#ifndef SAVINGSSUBACCOUNT_CPP
#define SAVINGSSUBACCOUNT_CPP
#include "savingssubaccount.h"
#include "checkingssubaccount.h"


int totalSavBalance = 0;

SavingsSubAccount::SavingsSubAccount(int bal) {
  balance = bal;
}

void SavingsSubAccount::printInfo() {
  cout << "\t| Sub-account number: SAV" << getSubAccNum() << endl;
  cout << "\t| Balance: " << getBalance() << endl << endl << endl;
}

int SavingsSubAccount::subAccMenu() {
  string userInput;
  
  cout << "Eligibile services for sub-account SAV" << subAccNum << endl;
  cout << "\tD -- Deposit" << endl;
  cout << "\tW -- Withdraw" << endl;
  cout << "\tX -- Exit" << endl;
  cout << "Please enter your selection: ";
  cin >> userInput;

  if (userInput == "D" || userInput == "d") {
    return deposit();
  }
  else if (userInput == "W" || userInput == "W") {
    return withdraw();
  }
  else if (userInput == "X" || userInput == "x") {
    cout << "\t| End of service for sub-account SAV" << subAccNum << endl << endl;
    return 0;
  }
  return 0;
}

int SavingsSubAccount::deposit() {
  int amt = 0;

  cout << "\tEnter the amount to deposit: ";
  cin >> amt;

  setBalance(getBalance() + amt);

  cout << "\t| Deposit was successful." << endl;
  cout << "\t| The current balance is " << balance << endl << endl;

  return amt;
}

int SavingsSubAccount::withdraw() {
  int amt = 0;

  cout << "\tEnter the amount to withdraw: ";
  cin >> amt;
  
  setBalance(getBalance() - amt);

  cout << "\t| Withdrawal was successful." << endl;
  cout << "\t| The current balance is " << balance << endl << endl;

  return amt * (-1);
}

#endif
#ifndef CHECKINGSSUBACCOUNT_CPP
#define CHECKINGSSUBACCOUNT_CPP
#include "checkingssubaccount.h"

CheckingsSubAccount::CheckingsSubAccount(int bal, int max, string userIn) : SavingsSubAccount(bal) {
  setBalance(bal);
  setLockStatus(userIn);
  maxCapacity = max;
}

void CheckingsSubAccount::printInfo() {
  cout << "\t| Sub-account number: CHK" << getSubAccNum() << endl;
  cout << "\t| Balance: " << getBalance() << endl << endl;
  
  cout << "\t| The maximum capacity is: " << getMaxCapacity() << endl;
  if (getLockStatus()) {
    cout << "\t| The sub-account is locked." << endl << endl << endl;
  }
  else {
    cout << "\t| The sub-account is unlocked." << endl << endl << endl;
  }
}

void CheckingsSubAccount::setLockStatus(string userInput) {
  if (userInput == "L" || userInput == "l") {
    locked = true;
  }
  else {
    locked = false;
  }
}

int CheckingsSubAccount::subAccMenu() {
  string userInput;
  
  cout << "Eligibile services for sub-account CHK" << getSubAccNum() << endl;
  cout << "\tD -- Deposit" << endl;
  cout << "\tW -- Withdraw" << endl;
  cout << "\tC -- Max Capacity" << endl;
  cout << "\tL -- Lock Sub-Account" << endl;
  cout << "\tU -- Unlock Sub-Acount" << endl;
  cout << "\tX -- Exit" << endl;
  cout << "Please enter your selection: ";
  cin >> userInput;

  if (userInput == "D" || userInput == "d") {
    return deposit();
  }
  else if (userInput == "W" || userInput == "W") {
    return withdraw();
  }
  else if (userInput == "C" || userInput == "c") {
    int maxCap;
    cout << "Enter new max capacity: ";
    cin >> maxCap;
    setMaxCapacity(maxCap);
  }
  else if (userInput == "L" || userInput == "l") {
    setLockStatus("l");
    cout << "\t| The sub-account CHK" << getSubAccNum() << " is locked now!" << endl << endl;
    subAccMenu();
  }
  else if (userInput == "U" || userInput == "u") {
    setLockStatus("u");
    cout << "\t| The sub-account CHK" << getSubAccNum() << " is unlocked now!" << endl << endl;
    subAccMenu();
  }
  else if (userInput == "X" || userInput == "x") {
    cout << "\t| End of service for sub-account CHK" << getSubAccNum() << endl << endl;
  }
}

int CheckingsSubAccount::deposit() {
  int amt;

  cout << "\tEnter the amount to deposit: ";
  cin >> amt;

  if (locked) {
    cout << "\t| The account is currently locked!" << endl;
    cout << "\t| The deposit was unsuccessfull." << endl << endl;
  }
  else if (getBalance() + amt > maxCapacity) {
      cout << "\t| Amount cannot exceed maximum capacity!" << endl;
      cout << "\t| The deposit was unsuccessfull." << endl << endl;
  }
  else {
    
    setBalance(getBalance() + amt);

    cout << "\t| Deposit was successful." << endl;
    cout << "\t| The current balance is " << getBalance() << endl << endl;

    return amt;
  }
  return 0;
}

int CheckingsSubAccount::withdraw() {
  int amt = 0;

  cout << "\tEnter the amount to withdraw: ";
  cin >> amt;

  if (locked) {
    cout << "\t| The account is currently locked!" << endl;
    cout << "\t| The deposit was unsuccessfull." << endl << endl;
  }
  else {
    setBalance(getBalance() - amt);
  
    cout << "\t| Withdrawal was successful." << endl;
    cout << "\t| The current balance is " << getBalance() << endl << endl;

    return amt * (-1);
  }

  return 0;
}

#endif
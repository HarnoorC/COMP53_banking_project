#ifndef BANKACCOUNT_CPP
#define BANKACCOUNT_CPP
#include "bankaccount.h"
#include "bank.h"


BankAccount::BankAccount(string firstName, string lastName, string SSN) {
    this->firstName = firstName;
    this->lastName = lastName;
    this->SSN = SSN;
    bankAccNum = 0;
}

void BankAccount::printBriefAccInfo() {
  cout << "\t| Aggregated Balance of the bank account: BNK" << getBankAccNum() << " with " << savSubAccounts.size() + checkingSubAccounts.size() << " Sub-Accounts is " << getAccAggBal() << endl;
}

void BankAccount::openSavAcc() {
  extern int numTotalSavAcc;
  int bal;
  
  cout << "\tEnter the inital balance: ";
  cin >> bal;

  SavingsSubAccount newSubAcc(bal);
  
  newSubAcc.setSubAccNum(numSavAcc + 1000);

  
  numSavAcc++;
  numTotalSavAcc++;

  if (newSubAcc.getSubAccNum() == 1000) {
    newSubAcc.setBalance(newSubAcc.getBalance() + 100);
    bal += 100;
  }

  accAggBal += newSubAcc.getBalance();
  
  savSubAccounts.push_back(newSubAcc);

  cout << "\t| A new Saving Sub-Account SAV" << newSubAcc.getSubAccNum() << " was successfully created." << endl << endl;

  //return bal;
}

void BankAccount::openCheckAcc() {
  extern int numTotalCheckAcc;
  int bal;
  int max;
  string userIn;

  cout << "\tEnter the initial balance: ";
  cin >> bal;

  cout << "\tEnter the desired maximum capacity: ";
  cin >> max;

  while (bal > max) {
    cout << "\tBalance cannot be greater than max!" << endl;
    cout << "\tEnter the initial balance: ";
    cin >> bal;
    cout << "\tEnter the desired maximum capacity: ";
    cin >> max;
  }

  cout << "\tDefine initial state: (L - Locked, Otherwise - Unlocked) ";
  cin >> userIn;

  CheckingsSubAccount newSubAcc(bal, max, userIn);

  newSubAcc.setSubAccNum(numCheckAcc + 6000);

  checkingSubAccounts.push_back(newSubAcc);

  accAggBal += bal;
  cout << accAggBal << endl;
  numCheckAcc++;
  numTotalCheckAcc++;

  cout << "\t| A new Checking Sub-Account CHK" << newSubAcc.getSubAccNum() << " was successfully created." << endl << endl;

  //return bal;
}

void BankAccount::closeSubAcc() {
  string userInput;
  
  cout << "\tEnter the sub-account number to modify: ";
  cin >> userInput;
  
  string subAccType;
  string strNum;

  for (int i = 0; i < 3; i++) {
    subAccType.push_back(userInput.at(i));
  }

  for (int i = 3; i < userInput.size(); i++) {
    strNum.push_back(userInput.at(i));
  }

  int num = stoi(strNum);

  if (subAccType == "SAV") {
    vector<SavingsSubAccount>::iterator ptr;
    for (ptr = savSubAccounts.begin(); ptr < savSubAccounts.end(); ptr++) {
      if (ptr->getSubAccNum() == num) {
        accAggBal -= ptr->getBalance();
        savSubAccounts.erase(ptr);
      }
    }
  }
  else if (subAccType == "CHK") {
    vector<CheckingsSubAccount>::iterator ptr;
    for (ptr = checkingSubAccounts.begin(); ptr < checkingSubAccounts.end(); ptr++) {
      if (ptr->getSubAccNum() == num) {
        accAggBal -= ptr->getBalance();
        checkingSubAccounts.erase(ptr);
      }
    }
  }

  cout << "\t| Sub-Account " << subAccType << num << " was successfully closed." << endl << endl;
}

void BankAccount::printDetailedAccInfo() {
  vector<SavingsSubAccount> sortedSavSubAccounts = savSubAccounts;
  vector<CheckingsSubAccount> sortedCheckingsSubAccounts = checkingSubAccounts;

  sort(sortedSavSubAccounts.begin(), sortedSavSubAccounts.end(), sortBySavSubAccBal);

  sort(sortedCheckingsSubAccounts.begin(), sortedCheckingsSubAccounts.end(), sortByCheckingsSubAccBal);

  for (int i = 0; i < sortedSavSubAccounts.size(); i++) {
    sortedSavSubAccounts.at(i).printInfo();
  }

  for (int i = 0; i < sortedCheckingsSubAccounts.size(); i++) {
    sortedCheckingsSubAccounts.at(i).printInfo();
  }
  
}

void BankAccount::bankAccMenu() {
  string userInput;
  
  cout << "Eligible services for BNK" << bankAccNum << endl;
  cout << "\tS -- Open Saving Sub-Account" << endl;
  cout << "\tC -- Open Checking Sub-Account" << endl;
  cout << "\tM -- Modify a Sub-Account" << endl;
  cout << "\tE -- Close a Sub-Account" << endl;
  cout << "\tD -- Detailed Bank Account Info Sorted Based on Balances of Sub-Accounts" << endl;
  cout << "\tB -- Brief Bank Account Info" << endl;
  cout << "\tX -- Exit" << endl;

  cout << "Please enter your selection: ";
  cin >> userInput;

  if (userInput == "S" || userInput == "s") {
    //return openSavAcc();
    openSavAcc();
    bankAccMenu();
  }
  else if (userInput == "C" || userInput == "c") {
    //return openCheckAcc();
    openCheckAcc();
    bankAccMenu();
  }
  else if (userInput == "M" || userInput == "m") {
    string userInput;
    
    cout << "\tEnter the sub-account number to modify: ";
    cin >> userInput;
    
    string subAccType;
    string strNum;

    for (int i = 0; i < 3; i++) {
      subAccType.push_back(userInput.at(i));
    }

    for (int i = 3; i < userInput.size(); i++) {
      strNum.push_back(userInput.at(i));
    }

    int num = stoi(strNum);

    if (subAccType == "SAV") {
      vector<SavingsSubAccount>::iterator ptr;
      for (ptr = savSubAccounts.begin(); ptr < savSubAccounts.end(); ptr++) {
        if (ptr->getSubAccNum() == num) {
          int temp = ptr->subAccMenu();
          accAggBal += temp;

          //return temp;
        }
      }
    }
    else if (subAccType == "CHK") {
      vector<CheckingsSubAccount>::iterator ptr;
      for (ptr = checkingSubAccounts.begin(); ptr < checkingSubAccounts.end(); ptr++) {
        if (ptr->getSubAccNum() == num) {
          int temp = ptr->subAccMenu();
          accAggBal += temp;

          //return temp;
        }
      }
    }
    
    bankAccMenu();
  }
  else if (userInput == "E" || userInput == "e") {
    closeSubAcc();
    bankAccMenu();
  }
  else if (userInput == "D" || userInput == "d") {
    printDetailedAccInfo();
    bankAccMenu();
  }
  else if (userInput == "B" || userInput == "b") {
    printBriefAccInfo();
    bankAccMenu();
  }
  else if (userInput == "X" || userInput == "x") {
    cout << endl;
    cout << "\t| End of service for bank-account BNK" << bankAccNum << endl << endl;
    
  }
  
}

#endif
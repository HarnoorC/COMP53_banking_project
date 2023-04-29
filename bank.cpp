#ifndef BANK_CPP
#define BANK_CPP
#include "bank.h"

int numTotalSavAcc = 0;
int numTotalCheckAcc = 0;


Bank::Bank() {
  
    string userInput;
    cout << "Enter the name of the bank: ";
    getline(cin, userInput);
    name = userInput;

    cout << "Enter the address of the bank: ";
    getline(cin, userInput);
    address = userInput;

    cout << "Enter the working hours: ";
    getline(cin, userInput);
    workingHours = userInput;
    cout << endl;

    bankMenu();
}

void Bank::printSortedInfo() {
  cout << endl;
  cout << "\t| Bank Name: " << getName() << endl;
  cout << "\t| Bank Address: " << getAddress() << endl;
  cout << "\t| Bank Working Hours: " << getWorkingHours() << endl;
  
  aggregatedBalance = 0;
  
  for (int i = 0; i < accounts.size(); i++) {
    aggregatedBalance += accounts.at(i).getAccAggBal();
  }
  
  cout << "\t| Aggregated Balance: " << aggregatedBalance << endl;
  cout << "\t| Consists of " << accounts.size() << " Bank-Accounts" << endl;

  vector<BankAccount> sortedAccounts = accounts;

  sort(sortedAccounts.begin(), sortedAccounts.end(), sortByAccAggBal);

  for (int i = 0; i < sortedAccounts.size(); i++) {
    sortedAccounts.at(i).printBriefAccInfo();
  }
}

void Bank::printDetailedInfo() {
  cout << "\t| Bank Name: " << name << endl;
  cout << "\t| Bank Address: " << address << endl;
  cout << "\t| Bank Working Hours: " << workingHours << endl;

  aggregatedBalance = 0;
  
  for (int i = 0; i < accounts.size(); i++) {
    aggregatedBalance += accounts.at(i).getAccAggBal();
  }
  
  cout << "\t| Aggregated Balance: " << aggregatedBalance << endl;
  cout << "\t| Consists of " << numBankAcc << " Bank-Accounts" << endl << endl << endl;

  for (int i = 0; i < accounts.size(); i++) {
    cout << "\t| Bank Account Number: BNK" << accounts.at(i).getBankAccNum() << endl;
    cout << "\t| Account Holder Full Name: " << accounts.at(i).getFullName() << endl;
    cout << "\t| Account Holder SSN: " << accounts.at(i).getSSN() << endl;
    cout << "\t| Aggregated Balance: " << accounts.at(i).getAccAggBal() << endl;
    cout << "\t| Consists of " << accounts.at(i).getSavSubAccounts().size() + accounts.at(i).getCheckingSubAccounts().size() << " Sub-Accounts" << endl << endl;
    accounts.at(i).printDetailedAccInfo();
  }
}

void Bank::openBankAcc() {
    string accFirstName;
    string accLastName;
    string accSSN;

    cout << "Enter the first name of the account holder: ";
    cin >> accFirstName;

    cout << "Enter the last name of the account holder: ";
    cin >> accLastName;

    cout << "Enter the SSN of the account holder: ";
    cin >> accSSN;
    cout << endl;

    BankAccount newAcc(accFirstName, accLastName, accSSN);

    newAcc.setBankAccNum(10000 + numBankAcc);

    numBankAcc++;

    cout << "A new Bank Account BNK" << newAcc.getBankAccNum() << " was successfully created." << endl << endl;

    //aggregatedBalance += newAcc.bankAccMenu();

    newAcc.bankAccMenu();

    accounts.push_back(newAcc);
    
}

void Bank::closeBankAcc() {
  string userInput;
      
      cout << "\tEnter the account number to be closed (BNK#####): ";
      cin >> userInput;

      string strNum;

      for (int i = 3; i < userInput.size(); i++) {
        strNum.push_back(userInput.at(i));
      }

      int num = stoi(strNum);

      vector<BankAccount>::iterator ptr;

      for (ptr = accounts.begin(); ptr < accounts.end(); ptr++) {
        if (ptr->getBankAccNum() == num) {
          //aggregatedBalance -= ptr->getAccAggBal();
          accounts.erase(ptr);
        }
      }

      cout << "\t| Account BNK" << num << " was successfully closed." << endl << endl;
}



void Bank::bankMenu() {
    string userInput;
    
    cout << "Eligible services for " << name << endl;
    cout << "\tA -- Number of Bank Accounts" << endl;
    cout << "\tS -- Number of Saving Accounts" << endl;
    cout << "\tH -- Number of Checking Accounts" << endl;
    cout << "\tO -- Open Bank Account" << endl;
    cout << "\tC -- Close Bank Account" << endl;
    cout << "\tM -- Modify Bank Account" << endl;
    cout << "\tD -- Detailed Bank-Accounts" << endl;
    cout << "\tB -- Brief Bank Accounts Info Sorted Based on Aggregated Balances" << endl;
    cout << "\tX -- Exit" << endl;

    cout << "Please enter your selection: ";
    cin >> userInput;
    cout << endl;

    if (userInput == "A" || userInput == "a") {
        cout << "Number of bank accounts: " << numBankAcc << endl << endl;
        bankMenu();
    }
    else if (userInput == "S" || userInput == "s") {
        cout << "Number of savings accounts: " << numTotalSavAcc << endl << endl;
        bankMenu();
    }
    else if (userInput == "H" || userInput == "h") {
        cout << "Number of checkings accounts: " << numTotalCheckAcc << endl << endl;
        bankMenu();
    }
    else if (userInput == "O" || userInput == "o") {
      openBankAcc();
      //cout << aggregatedBalance << endl;
      bankMenu();
      
    }
    else if (userInput == "C" || userInput == "c") {
      closeBankAcc();
      //cout << aggregatedBalance << endl;
      bankMenu();
    }
    else if (userInput == "M" || userInput == "m") {
      string userInput;
      
      cout << "\tEnter the account number to modify: ";
      cin >> userInput;

      string strNum;

      for (int i = 3; i < userInput.size(); i++) {
        strNum.push_back(userInput.at(i));
      }

      int num = stoi(strNum);
      
      vector<BankAccount>::iterator ptr;
      
      for (ptr = accounts.begin(); ptr < accounts.end(); ptr++) {
        if (ptr->getBankAccNum() == num) {
          ptr->bankAccMenu();
        }
      }

      cout << endl;

      bankMenu();
    }
    else if (userInput == "D" || userInput == "d") {
      printDetailedInfo();
      bankMenu();
    }
    else if (userInput == "B" || userInput == "b") {
      printSortedInfo();
      bankMenu();
    }
    else if (userInput == "X" || userInput == "x") {
      cout << "\t| End of service for bank " << name << endl << endl;
    }
    else {
      cout << "INVALID INPUT" << endl;
    }
    
}

#endif
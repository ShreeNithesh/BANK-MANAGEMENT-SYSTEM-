#include "Account.h"

Account::Account() {}

Account::Account(string ano, string aname, double bal) {
    accountNumber = ano;
    accountHolderName = aname;
    balance = bal;
}

void Account::deposit(double amount) {
    if (amount <= 0) {
        throw invalid_argument("Deposit amount must be greater than zero.");
    }

    balance += amount;
    cout << "Deposited Rs." << amount << " into account " << accountNumber << endl;
}

void Account::withdraw(double amount) {
    if (amount <= 0) {
        throw invalid_argument("Withdrawal amount must be greater than zero.");
    }

    if (balance >= amount) {
        balance -= amount;
        cout << "Withdrawn Rs." << amount << " from account " << accountNumber << endl;
    } else {
        throw runtime_error("Insufficient balance in account " + accountNumber);
    }
}

void Account::display() {
    cout << "Account Number: " << accountNumber << "||" << "Account Holder Name: " << accountHolderName << "||" << "Balance: Rs." << balance << endl;
}

string Account::getAccountNumber() {
    return accountNumber;
}

void Account::saveToFile(ofstream &file) {
    file << accountNumber << " " << accountHolderName << " " << balance << endl;
}

// Implementations for derived classes
SavingsAccount::SavingsAccount(string ano, string aname, double intRate, double minBal, int l) : Account(ano, aname) {
    interestRate = intRate;
    minimumBalance = minBal;
    withdrawalLimit = l;
}

void SavingsAccount::deposit(double amount) {
    Account::deposit(amount);
    calculateInterest();
}

void SavingsAccount::withdraw(double amount) {
    if (balance - amount >= minimumBalance) {
        Account::withdraw(amount);
    } else {
        cout << "Withdrawal amount exceeds minimum balance requirement" << endl;
    }
}

void SavingsAccount::display() {
    cout << "Savings Account Details" << endl;
    Account::display();
}

void SavingsAccount::calculateInterest() {
    double interest = balance * (interestRate / 100);
    balance += interest;
    cout << "Interest accrued: Rs." << interest << endl;
}

// Implementations for other classes follow similarly...


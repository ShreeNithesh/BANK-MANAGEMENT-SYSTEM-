#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>

using namespace std;

class Account {
protected:
    string accountNumber;
    string accountHolderName;
    double balance;

public:
    Account();
    Account(string ano, string aname, double bal = 0);

    virtual void deposit(double amount);
    virtual void withdraw(double amount);
    virtual void display();

    string getAccountNumber();
    void saveToFile(ofstream &file);
};

class SavingsAccount : public Account {
private:
    double interestRate;
    double minimumBalance;
    int withdrawalLimit;

public:
    SavingsAccount(string ano, string aname, double intRate, double minBal, int l);
    void deposit(double amount) override;
    void withdraw(double amount) override;
    void display() override;
    void calculateInterest();
};

class CheckingAccount : public Account {
private:
    double overdraftLimit;
    int monthlyTransactionLimit;
    int remainingTransactions;

public:
    CheckingAccount();
    CheckingAccount(string accNumber, string accHolderName, double odlim, int monthlyTransLim);
    void deposit(double amount) override;
    void withdraw(double amount) override;
    void display() override;
};

class LoanAccount : public Account {
private:
    double loanAmount;
    double interestRate;
    int repaymentPeriod;

public:
    LoanAccount();
    LoanAccount(string accNumber, string accHolderName, double loanAmt, double intRate, int repayPeriod);
    void deposit(double amount) override;
    void withdraw(double amount) override;
    void display() override;
};

class InvestmentAccount : public Account {
private:
    string investmentType;

public:
    InvestmentAccount();
    InvestmentAccount(string accNumber, string accHolderName, string invType);
    void deposit(double amount) override;
    void withdraw(double amount) override;
    void display() override;
};

class CreditCardAccount : public Account {
private:
    double creditLimit;
    double interestRate;

public:
    CreditCardAccount();
    CreditCardAccount(string accNumber, string accHolderName, double creditLim, double intRate);
    void deposit(double amount) override;
    void withdraw(double amount) override;
    void display() override;
};

#endif // ACCOUNT_H

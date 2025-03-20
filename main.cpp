#include "Account.h"
#include <vector>
#include <fstream>

// Function to read accounts from file
void readAccountsFromFile(vector<Account*>& accounts) {
    ifstream file("ACCOUNTS.dat");
    if (!file.is_open()) {
        cout << "File not found. Creating a new file." << endl;
        return;
    }

    string accNumber, accHolderName;
    double balance;
    while (file >> accNumber >> accHolderName >> balance) {
        accounts.push_back(new Account(accNumber, accHolderName, balance));
    }
    file.close();
}

// Function to write accounts to file
void writeAccountsToFile(const vector<Account*>& accounts) {
    ofstream file("ACCOUNTS.dat");
    if (!file.is_open()) {
        cout << "Unable to open file for writing." << endl;
        return;
    }

    for (const auto& acc : accounts) {
        acc->saveToFile(file);
    }
    file.close();
}

// Helper functions for input validation
bool isAlphaString(const string& str) {
    for (char c : str) {
        if (!isalpha(c)) {
            return false;
        }
    }
    return true;
}

bool isNumericString(const string& str) {
    for (char c : str) {
        if (!isdigit(c)) {
            return false;
        }
    }
    return true;
}

int main() {
    vector<Account*> accounts;

    readAccountsFromFile(accounts);

    while (true) {
        cout << "===== Main Menu =====" << endl;
        cout << "1. Create Savings Account" << endl;
        cout << "2. Create Checking Account" << endl;
        cout << "3. Create Loan Account" << endl;
        cout << "4. Create Investment Account" << endl;
        cout << "5. Create Credit Card Account" << endl;
        cout << "6. Deposit Money" << endl;
        cout << "7. Withdraw Money" << endl;
        cout << "8. Display Account Details" << endl;
        cout << "9. Exit" << endl;

        try {
            int choice;
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice) {
                // Implementations for each choice...
            }
        } catch (const exception& e) {
            cout << "Error: " << e.what() << endl;
        }
    }

    return 0;
}

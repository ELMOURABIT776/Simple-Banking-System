#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Account {
    string name;
    int accountNumber;
    double balance;
};

class BankingSystem {
private:
    vector<Account> accounts;
    int nextAccountNumber = 1001;

public:
    void createAccount(string name) {
        Account newAccount = {name, nextAccountNumber++, 0.0};
        accounts.push_back(newAccount);
        cout << "Account created for " << name << " with account number " << newAccount.accountNumber << endl;
    }

    void deposit(int accountNumber, double amount) {
        for (auto &account : accounts) {
            if (account.accountNumber == accountNumber) {
                account.balance += amount;
                cout << "Deposited " << amount << " into account " << accountNumber << endl;
                return;
            }
        }
        cout << "Account not found.\n";
    }

    void withdraw(int accountNumber, double amount) {
        for (auto &account : accounts) {
            if (account.accountNumber == accountNumber) {
                if (account.balance >= amount) {
                    account.balance -= amount;
                    cout << "Withdrew " << amount << " from account " << accountNumber << endl;
                } else {
                    cout << "Insufficient balance.\n";
                }
                return;
            }
        }
        cout << "Account not found.\n";
    }

    void checkBalance(int accountNumber) {
        for (auto &account : accounts) {
            if (account.accountNumber == accountNumber) {
                cout << "Account " << accountNumber << " balance: " << account.balance << endl;
                return;
            }
        }
        cout << "Account not found.\n";
    }
};

int main() {
    BankingSystem bank;
    int choice;
    do {
        cout << "1. Create Account\n2. Deposit\n3. Withdraw\n4. Check Balance\n5. Exit\n";
        cin >> choice;
        if (choice == 1) {
            string name;
            cout << "Enter account holder name: ";
            cin >> name;
            bank.createAccount(name);
        } else if (choice == 2) {
            int accountNumber;
            double amount;
            cout << "Enter account number: ";
            cin >> accountNumber;
            cout << "Enter deposit amount: ";
            cin >> amount;
            bank.deposit(accountNumber, amount);
        } else if (choice == 3) {
            int accountNumber;
            double amount;
            cout << "Enter account number: ";
            cin >> accountNumber;
            cout << "Enter withdrawal amount: ";
            cin >> amount;
            bank.withdraw(accountNumber, amount);
        } else if (choice == 4) {
            int accountNumber;
            cout << "Enter account number: ";
            cin >> accountNumber;
            bank.checkBalance(accountNumber);
        }
    } while (choice != 5);

    return 0;
}

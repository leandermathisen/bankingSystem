#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> bankNumbers;

class bankAccount {
    public:
        int bankAccountNumber;
        int balance;
        int pin;
        string name;
};

vector<bankAccount> bankAccounts;

int createAccount (int amount, int pin, string name) {
    int bankNumber = bankAccounts.size() + 1;
    bankAccount account;
    bankNumbers[bankNumber-1] = bankNumber;
    account.bankAccountNumber = bankNumber;
    account.balance = amount;
    account.pin = pin;
    account.name = name;
    bankAccounts.push_back(account);
    return bankNumber;
}

void transfer (int transferAmount, int bankNumber1, int bankNumber2) {
    if (bankNumbers[bankNumber1-1] == 0 || bankNumbers[bankNumber2-1] == 0)
        cout << "The bank account was not found" << endl;
    else {
        bankAccounts[bankNumber1-1].balance -= transferAmount;
        bankAccounts[bankNumber2-1].balance += transferAmount;
    }
    cin.ignore();
}

void withdrawal (int withdrawalAmount, int bankNumber) {
    if (bankNumbers[bankNumber-1] == 0)
        cout << "The bank account was not found" << endl;
    else
        bankAccounts[bankNumber-1].balance -= withdrawalAmount;
    cin.ignore();
}

void deposit (int depositAmount, int bankNumber) {
    if (bankNumbers[bankNumber-1] == 0)
        cout << "The bank account was not found" << endl;
    else
        bankAccounts[bankNumber-1].balance += depositAmount;
    cin.ignore();
}

void checkBalance (int bankNumber) {
    if (bankNumbers[bankNumber-1] == 0)
        cout << "The bank account was not found" << endl;
    else
        cout << "Your balance is " << bankAccounts[bankNumber-1].balance << endl;
    cin.ignore();
}

int main () {
    string command, name;
    int amount, bankNumber, bankNumber1, bankNumber2, pin;

    bankNumbers.reserve(1000);
    for (int i=0; i < 1000; i++) {
        bankNumbers[i] = 0;
    }

    cout << "Welcome to the Bank" << endl;

    while (true) {

        cout << "Enter a command or exit: ";
        getline(cin, command);

        if (command == "create account") {
            cout << "Okay enter the amount you would like to deposit" << endl;
            cin >> amount;
            cout << "Enter a 4 digit pin" << endl;
            cin >> pin;
            cin.ignore();
            cout << "Enter your name: ";
            getline(cin, name);
            bankNumber = createAccount(amount, pin, name);
            cout << "Your bank number is " << bankNumber << endl;
        }
        else if (command == "transfer") {
            cout << "Enter the amount the first bank number and the second bank number" << endl;
            cin >> amount >> bankNumber1 >> bankNumber2;
            transfer(amount, bankNumber1, bankNumber2);
        }
        else if (command == "withdrawal") {
            cout << "Enter the withdrawal amount and the bank account number" << endl;
            cin >> amount >> bankNumber;
            withdrawal(amount, bankNumber);
        }
        else if (command == "deposit") {
            cout << "Enter the deposit amount and the bank account number" << endl;
            cin >> amount >> bankNumber;
            deposit(amount, bankNumber);
        }
        else if (command == "check balance") {
            cout << "Enter your bank account number" << endl;
            cin >> bankNumber;
            checkBalance(bankNumber);
        }
        else if (command == "exit") {
            break;
        }
        else {
            cout << "Enter a proper command" << endl;
        }
    }

    cout << "Thank you for using our Bank" << endl;

    return 0;
}
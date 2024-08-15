#include <iostream>
#include <string>

using namespace std;

const int MAX_ACCOUNTS = 100;

int accountNumbers[MAX_ACCOUNTS];
string accountHolders[MAX_ACCOUNTS];
double balances[MAX_ACCOUNTS];
int totalAccounts = 0;

void createAccount() {
    if (totalAccounts >= MAX_ACCOUNTS) {
        cout << "Cannot create more accounts. Maximum limit reached." << endl;
        return;
    }

    cout << "Enter Account Number: ";
    cin >> accountNumbers[totalAccounts];

    cout << "Enter Account Holder's Name: ";
    cin.ignore();
    getline(cin, accountHolders[totalAccounts]);

    cout << "Enter Initial Balance: ";
    cin >> balances[totalAccounts];

    if (balances[totalAccounts] < 0) {
        cout << "Invalid balance! Initial balance cannot be negative." << endl;
        return;
    }

    totalAccounts++;
    cout << "Account created successfully!" << endl;
}

void depositMoney() {
    int accountNumber;
    double amount;

    cout << "Enter Account Number: ";
    cin >> accountNumber;

    int index = -1;
    for (int i = 0; i < totalAccounts; i++) {
        if (accountNumbers[i] == accountNumber) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        cout << "Account not found!" << endl;
        return;
    }

    cout << "Enter Amount to Deposit: ";
    cin >> amount;

    if (amount <= 0) {
        cout << "Invalid deposit amount." << endl;
        return;
    }

    balances[index] += amount;
    cout << "Deposit successful!" << endl;
}

void withdrawMoney() {
    int accountNumber;
    double amount;

    cout << "Enter Account Number: ";
    cin >> accountNumber;

    int index = -1;
    for (int i = 0; i < totalAccounts; i++) {
        if (accountNumbers[i] == accountNumber) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        cout << "Account not found!" << endl;
        return;
    }

    cout << "Enter Amount to Withdraw: ";
    cin >> amount;

    if (amount <= 0) {
        cout << "Invalid withdrawal amount." << endl;
        return;
    }

    if (balances[index] < amount) {
        cout << "Insufficient balance!" << endl;
        return;
    }

    balances[index] -= amount;
    cout << "Withdrawal successful!" << endl;
}

void checkBalance() {
    int accountNumber;

    cout << "Enter Account Number: ";
    cin >> accountNumber;

    int index = -1;
    for (int i = 0; i < totalAccounts; i++) {
        if (accountNumbers[i] == accountNumber) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        cout << "Account not found!" << endl;
        return;
    }

    cout << "Account Holder: " << accountHolders[index] << endl;
    cout << "Current Balance: $" << balances[index] << endl;
}

int main() {
    int choice;

    do {
        cout << "\nSimple Banking System" << endl;
        cout << "1. Create Account" << endl;
        cout << "2. Deposit Money" << endl;
        cout << "3. Withdraw Money" << endl;
        cout << "4. Check Balance" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                createAccount();
                break;
            case 2:
                depositMoney();
                break;
            case 3:
                withdrawMoney();
                break;
            case 4:
                checkBalance();
                break;
            case 5:
                cout << "Exiting program..." << endl;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 5);

    return 0;
}
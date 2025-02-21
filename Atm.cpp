#include <iostream>
using namespace std;

class ATM {
private:
    double balance;

public:
    ATM(double initialBalance) {
        balance = initialBalance;
    }

    void checkBalance() {
        cout << "Your balance is: $" << balance << endl;
    }

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposited: $" << amount << endl;
            checkBalance();
        } else {
            cout << "Invalid deposit amount." << endl;
        }
    }

    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Withdrawn: $" << amount << endl;
            checkBalance();
        } else {
            cout << "Invalid withdrawal amount or insufficient funds." << endl;
        }
    }
};

int main() {
    ATM myATM(500.00);
    int choice;
    double amount;

    do {
        cout << "\nATM Menu:\n1. Check Balance\n2. Deposit\n3. Withdraw\n4. Exit\nEnter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                myATM.checkBalance();
                break;
            case 2:
                cout << "Enter deposit amount: ";
                cin >> amount;
                myATM.deposit(amount);
                break;
            case 3:
                cout << "Enter withdrawal amount: ";
                cin >> amount;
                myATM.withdraw(amount);
                break;
            case 4:
                cout << "Thank you for using the ATM!" << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 4);

    return 0;
}

#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

class Transaction {
public:
    string type;
    double amount;

    Transaction(string t, double a) {
        type = t;
        amount = a;
    }
};

class Account {
public:
    int accountNumber;
    double balance;
    vector<Transaction> history;

    Account(int accNo) {
        accountNumber = accNo;
        balance = 0;
    }

    void deposit(double amount) {
        balance += amount;
        history.push_back(Transaction("Deposit", amount));
        cout << "Deposit Successful!\n";
    }

    void withdraw(double amount) {
        if (amount <= balance) {
            balance -= amount;
            history.push_back(Transaction("Withdraw", amount));
            cout << "Withdrawal Successful!\n";
        } else {
            cout << "Insufficient Balance!\n";
        }
    }

    void transfer(Account &receiver, double amount) {
        if (amount <= balance) {
            balance -= amount;
            receiver.balance += amount;

            history.push_back(Transaction("Transfer Sent", amount));
            receiver.history.push_back(Transaction("Transfer Received", amount));

            cout << "Transfer Successful!\n";
        } else {
            cout << "Insufficient Balance!\n";
        }
    }

    void showTransactions() {
        cout << "\nTransaction History\n";
        cout << "------------------------\n";

        if (history.empty()) {
            cout << "No Transactions Found.\n";
            return;
        }

        for (int i = 0; i < history.size(); i++) {
            cout << history[i].type
                 << " : Rs. "
                 << fixed << setprecision(2)
                 << history[i].amount << endl;
        }
    }
};

class Customer {
public:
    string name;
    int customerID;
    Account account;

    Customer(string n, int id, int accNo)
        : account(accNo) {
        name = n;
        customerID = id;
    }

    void showDetails() {
        cout << "\nCustomer Name : " << name << endl;
        cout << "Customer ID   : " << customerID << endl;
        cout << "Account No    : " << account.accountNumber << endl;
        cout << "Balance       : Rs. "
             << fixed << setprecision(2)
             << account.balance << endl;
    }
};

int main() {

    vector<Customer> customers;
    int choice;

    do {

        cout << "\n========== BANKING SYSTEM ==========\n";
        cout << "1. Create Customer\n";
        cout << "2. Deposit\n";
        cout << "3. Withdraw\n";
        cout << "4. Fund Transfer\n";
        cout << "5. Account Details\n";
        cout << "6. Transaction History\n";
        cout << "7. Exit\n";
        cout << "Enter Choice : ";
        cin >> choice;

        if (choice == 1) {

            string name;
            int id, accNo;

            cout << "Enter Customer Name : ";
            cin >> name;

            cout << "Enter Customer ID : ";
            cin >> id;

            cout << "Enter Account Number : ";
            cin >> accNo;

            customers.push_back(Customer(name, id, accNo));

            cout << "Customer Created Successfully!\n";
        }

        else if (choice == 2) {

            int acc;
            double amount;

            cout << "Enter Account Number : ";
            cin >> acc;

            cout << "Enter Amount : ";
            cin >> amount;

            bool found = false;

            for (auto &c : customers) {
                if (c.account.accountNumber == acc) {
                    c.account.deposit(amount);
                    found = true;
                    break;
                }
            }

            if (!found)
                cout << "Account Not Found!\n";
        }

        else if (choice == 3) {

            int acc;
            double amount;

            cout << "Enter Account Number : ";
            cin >> acc;

            cout << "Enter Amount : ";
            cin >> amount;

            bool found = false;

            for (auto &c : customers) {
                if (c.account.accountNumber == acc) {
                    c.account.withdraw(amount);
                    found = true;
                    break;
                }
            }

            if (!found)
                cout << "Account Not Found!\n";
        }

        else if (choice == 4) {

            int from, to;
            double amount;

            cout << "Enter Sender Account : ";
            cin >> from;

            cout << "Enter Receiver Account : ";
            cin >> to;

            cout << "Enter Amount : ";
            cin >> amount;

            Account *sender = nullptr;
            Account *receiver = nullptr;

            for (auto &c : customers) {

                if (c.account.accountNumber == from)
                    sender = &c.account;

                if (c.account.accountNumber == to)
                    receiver = &c.account;
            }

            if (sender && receiver)
                sender->transfer(*receiver, amount);
            else
                cout << "Invalid Account Number!\n";
        }

        else if (choice == 5) {

            int acc;
            cout << "Enter Account Number : ";
            cin >> acc;

            bool found = false;

            for (auto &c : customers) {
                if (c.account.accountNumber == acc) {
                    c.showDetails();
                    found = true;
                }
            }

            if (!found)
                cout << "Account Not Found!\n";
        }

        else if (choice == 6) {

            int acc;
            cout << "Enter Account Number : ";
            cin >> acc;

            bool found = false;

            for (auto &c : customers) {
                if (c.account.accountNumber == acc) {
                    c.account.showTransactions();
                    found = true;
                }
            }

            if (!found)
                cout << "Account Not Found!\n";
        }

    } while (choice != 7);

    cout << "\nThank You for Using Banking System!\n";

    return 0;
}
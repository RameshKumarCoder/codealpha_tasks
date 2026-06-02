#include <iostream>
#include <vector>
using namespace std;

class Account {
private:
    string name;
    int accNo;
    float balance;
    vector<string> history;

public:
    Account(string n, int a, float b) {
        name = n;
        accNo = a;
        balance = b;
    }

    void deposit(float amount) {
        balance += amount;
        history.push_back("Deposited: " + to_string(amount));
    }

    void withdraw(float amount) {
        if (amount <= balance) {
            balance -= amount;
            history.push_back("Withdrawn: " + to_string(amount));
        } else {
            cout << "Insufficient balance!\n";
        }
    }

    void showDetails() {
        cout << "\nAccount Holder: " << name;
        cout << "\nAccount No: " << accNo;
        cout << "\nBalance: " << balance << endl;
    }

    void showHistory() {
        cout << "\n--- Transaction History ---\n";
        for (auto &h : history)
            cout << h << endl;
    }
};

int main() {
    Account acc("Ramesh", 1001, 5000);

    acc.deposit(2000);
    acc.withdraw(1500);

    acc.showDetails();
    acc.showHistory();

    return 0;
}
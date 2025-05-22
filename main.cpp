#include <iostream>
#include <random>
#include <sstream>
#include <iomanip>
using namespace std;

string generateUUID() {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(0, 15);
    uniform_int_distribution<> dist2(8, 11);

    stringstream ss;
    ss << hex;
    for (int i = 0; i < 8; i++) ss << dist(gen);
    ss << "-";
    for (int i = 0; i < 4; i++) ss << dist(gen);
    ss << "-4"; // version 4
    for (int i = 0; i < 3; i++) ss << dist(gen);
    ss << "-";
    ss << dist2(gen); // variant
    for (int i = 0; i < 3; i++) ss << dist(gen);
    ss << "-";
    for (int i = 0; i < 12; i++) ss << dist(gen);
    return ss.str();
}

class Bankacc {
private:
    string accno;
    string name;
    double balance;

public:
    Bankacc() {
        cout << "Welcome to Bank!\n";
    }

    void createAccount(string n, double b) {
        accno = generateUUID();
        name = n;
        balance = b;
        cout << "Bank Account is created!\n";
        cout << "Account Number: " << accno << "\n";
    }

    void deposit(double amount) {
        balance += amount;
        cout << "Successfully deposited: " << amount << "\n";
    }

    void withdraw(double amount) {
        if (amount > balance) {
            cout << "Insufficient balance!\n";
            return;
        }
        balance -= amount;
        cout << "Successfully withdrawn: " << amount << "\n";
    }

    double getBalance() {
        return balance;
    }

    void displayDetails() {
        cout << "Account Number: " << accno << "\n"
             << "Name: " << name << "\n"
             << "Balance: " << balance << "\n";
    }
};

int main() {
    Bankacc b1;
    b1.createAccount("abc", 10000);
    b1.deposit(500);
    b1.withdraw(200);
    cout << "Current Balance: " << b1.getBalance() << "\n";
    b1.displayDetails();

    return 0;
}

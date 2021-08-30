#ifndef BANK_ACCOUNT
#define BANK_ACCOUNT

#include<iostream>
#include<string>

using namespace std;

class Account {
private:
    string accountName;
    int accountNumber;
    int accountBalance;

    static double interest;

public:
    Account();

    Account(const string& name, const int& number, const int& balance);

    bool setName(const string& name);

    bool setNumber(const int& number);

    bool setBalance(const int& balance);

    string getName() const;

    int getNumber() const;

    int getBalance() const;

    bool deposit(const int& money);

    bool withdraw(const int& amount);

    void addInterest();

    void display() const;
};

Account::Account(): accountName(""), accountNumber(0), accountBalance(0) {
}

Account::Account(const string& name, const int& number, const int& balance) {
    setName(name);
    setNumber(number);
    setBalance(balance);
}

bool Account::setName(const string& name) {
    this->accountName = name;

    return true;
}

bool Account::setNumber(const int& number) {
    this->accountNumber = number;

    return true;
}

bool Account::setBalance(const int& balance) {
    this->accountBalance = balance;
    
    return true;
}

string Account::getName() const {
    return accountName;
}

int Account::getNumber() const {
    return accountNumber;
}

int Account::getBalance() const {
    return accountBalance;
}

bool Account::deposit(const int& money) {
    if (money < 0) return false;

    setBalance(accountBalance + money);

    return true;
}

bool Account::withdraw(const int& amount) {
    if (amount > accountBalance) return false;

    setBalance(accountBalance - amount);

    return true;
}

void Account::addInterest() {
    setBalance(accountBalance * (1.0 + interest / 100.0));
}

void Account::display() const {
    cout << "Customer name: " << getName() << endl;
    cout << "Account number: " << getNumber() << endl;
    cout << "Balance: " << getBalance() << endl; 
}
#endif
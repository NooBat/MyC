#ifndef CURRENCY
#define CURRENCY

#include<iostream>

using namespace std;

class Currency {
private:
    int dollar;
    int cent;

public:
    Currency();

    Currency(const int& dollar, const int& cent);

    bool setDollar(const int& dollar);

    bool setCent(const int& cent);

    int getDollar() const;

    int getCent() const;

    void display() const;
};

Currency::Currency(): dollar(0), cent(0) {
}

Currency::Currency(const int& dollar, const int& cent) {
    this->setDollar(dollar);
    this->setCent(cent);
}

bool Currency::setDollar(const int& dollar) {
    if (dollar < 0) return false;

    this->dollar = dollar;

    return true;
}

bool Currency::setCent(const int& cent) {
    if (cent < 0 || cent >= 100) return false;

    this->cent = cent;

    return true;
}

int Currency::getDollar() const {
    return this->dollar;
}

int Currency::getCent() const {
    return this->cent;
}

void Currency::display() const {
    cout << getDollar() << " dollars " << getCent() << " cents";
}
#endif
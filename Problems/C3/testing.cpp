#include "Ex1.h"
#include "Ex2.h"
#include "Ex3.h"
#include "Ex4.h"

bool calculateChange(Currency& money, const Currency& price) {
    int Money = money.getDollar() * 100 + money.getCent();
    int Price = price.getDollar() * 100 + price.getCent();
    int changeCent;
    int changeDollar = 0;

    if (Money < Price) return false;
    else if (Money == Price) {
        money.setCent(0);
        money.setDollar(0);
        return true;
    }
    else {
        changeCent = Money - Price;
    }

    while (changeCent >= 100) {
        changeDollar += changeCent / 100;
        changeCent %= 100;
    }

    money.setDollar(changeDollar);
    money.setCent(changeCent);

    return true;
}

void currencyTester(Currency& money) {
    cout << "display: prints ";
    money.display();
    cout << "; should be 0 dollars 0 cents";
    cout << endl;

    cout << endl << endl;

    
    int dollar = 29;
    int cent = 30;

    cout << "setDollar(" << dollar << "): returns " << money.setDollar(dollar)
         << "; should be 1 (true)" << endl;
    cout << "setCent(" << cent << "): returns " << money.setCent(cent)
         << "; should be 1 (true)" << endl;
    
    cout << "Now the money is ";
    money.display();
    cout << endl;

    cout << endl << endl;
    

    Currency price1(12, 50);
    cout << "display item 1: prints ";
    price1.display();
    cout << "; should be 12 dollars 50 cents";
    cout << endl;

    cout << "Use the money to buy item 1" << endl;
    cout << "calculateChange(money, price1): returns " << calculateChange(money, price1) 
         << "; should be 1 (true)" << endl;

    cout << "Now the money is: ";
    money.display();
    cout << endl;

    cout << endl << endl;
}

int main() {
    cout << "Testing Currency-ADT: " << endl;

    Currency money;

    currencyTester(money);

    cout << "All done!" << endl;
    return 0;
}
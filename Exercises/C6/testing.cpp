#include<iostream>
#include "Ex11.hpp"
#include "/Users/danielnguyen/Repo/C++/Problems/C5/Ex8.hpp"

using namespace std;

int main() {
    cout << "Testing postfix converter" << endl;

    Postfix pos("abc-d*+");

    cout << "Current postifx expression: " << pos.getExp() << endl;
    
    string exp = pos.toInfix();

    Infix inf(exp);
    cout << "After converting: " << inf.isInfix() << endl;

    return 0;
}
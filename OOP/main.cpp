#include "game.cpp"
#include "fraction.cpp"
#include<iostream>

using namespace std;

int main() {    
    Fraction a(1, 3);
    Fraction b(2, 7);
    Fraction c;
    c = a - b;
    c.print();

    Fraction d;
    d = 1 + a;
    cout << d << endl;

    return 0;
}
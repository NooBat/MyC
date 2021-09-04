#include "Ex5.h"
#include<iostream>

using namespace std;

int main() {
    Prefix pre = Prefix("*+/abc+de");
    string exp = pre.getExp();

    cout << pre.isPrefix() << endl;
    cout << pre.evaluatePrefix(0, exp.length() - 1);

    return 0;
}
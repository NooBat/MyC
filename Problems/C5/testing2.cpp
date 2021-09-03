#include "Ex5.h"
#include<iostream>

using namespace std;

int main() {
    Prefix pre = Prefix("+–/abc*+def*gh");

    string exp = pre.getExp();

    cout << exp << endl;

    string a = exp.substr(3, 1);

    cout << a;

    // cout << pre.evaluatePrefix(0, pre.getExp().length() - 1);

    return 0;
}
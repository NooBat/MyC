#include "Ex5.h"
#include<iostream>

using namespace std;

int main() {
    Prefix pre = Prefix("+–/abc*+def*gh");

    string exp = pre.getExp();

    cout << pre.evaluatePrefix(0, exp.length() - 1);

    return 0;
}
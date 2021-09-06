#include "Ex5.h"
#include "Ex7.h"
#include<iostream>

using namespace std;

int main() {
    // cout << "Input your expression: ";
    // string input;
    // getline(cin, input);


    InfixCalculator inf("7+(200/9)");

    try {
        cout << inf.evaluateInfix() << endl;
    }
    catch(exception &e) {
        cout << e.what();
    }

    return 0;
}
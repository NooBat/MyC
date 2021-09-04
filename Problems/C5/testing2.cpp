#include "Ex5.h"
#include "Ex8.h"
#include<iostream>

using namespace std;

int main() {
    Infix inf = Infix("((a-c)/b+d)");

    cout << inf.isInfix();

    return 0;
}
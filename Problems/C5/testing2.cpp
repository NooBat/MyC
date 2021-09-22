#include "Ex5.hpp"
#include "Ex8.hpp"
#include<iostream>

using namespace std;

int main() {
    Infix inf = Infix("((a-c)/b+d)");

    cout << inf.isInfix();

    return 0;
}
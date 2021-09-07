#include "Ex5.h"
#include "Ex7.h"
#include "Ex10.h"
#include<iostream>

using namespace std;

int main() {
    // cout << "Input your expression: ";
    // string input;
    // getline(cin, input);

    Solution obj;

    OurStack<int> result = obj.solveTower(10);

    while (!result.isEmpty()) {
        cout << result.peek() << " ";
        result.pop();
    }

    return 0;
}
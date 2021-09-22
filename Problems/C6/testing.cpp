#include "Ex5.hpp"
#include "Ex7.hpp"
#include "Ex10.hpp"
#include<iostream>

using namespace std;

int main() {
    // cout << "Input your expression: ";
    // string input;
    // getline(cin, input);

    Solution obj;

    LinkedStack<int> result = obj.solveTower(10);

    while (!result.isEmpty()) {
        cout << result.peek() << " ";
        result.pop();
    }

    return 0;
}
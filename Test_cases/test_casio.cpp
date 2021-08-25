#include<iostream>
#include<stack>
#include<queue>
#include<string>
#include<sstream>
#include<algorithm>

using namespace std;

int getNumber(queue<char> number) {
    string s;
    int result;
    
    while (!number.empty()) {
        s += number.front();
        number.pop();
    }

    auto it = s[0]; 

    stringstream ss;
    ss << s;
    ss >> result;

    return result;
}

void operator(int)
int getSyntax(string s) {
    queue<char> number;
    queue<char> operator;
    queue<char> parenthese;
    stack<char> syntax;
    for (int i = 0; i < s.length(); i++) {
        syntax.push(s[i]);
    }

    while (!syntax.empty()) {

    }
}
// int calculator(string s) {
//     int result;
    
// }

int main() {
    queue<char> s;
    s.push('1');
    s.push('2');
    cout << getNumber(s);


    return 0;
}
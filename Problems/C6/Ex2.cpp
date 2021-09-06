#include<stack>
#include<string>
#include<iostream>
#include<regex>

using namespace std;

bool isBalanced(const string& exp) {
    stack<char> st;

    const string openingBrackets = "([{";
    const string closingBrackets = ")]}";


    for (int i = 0; i < exp.length(); i++) {
        string temp = exp.substr(i, 1);

        if ((int)openingBrackets.find(temp) != -1) {
            st.push(exp[i]);
        }
        else if ((int)closingBrackets.find(temp) != -1) {
            if ((exp[i] == ')' && st.top() == '(') ||
                (exp[i] == ']' && st.top() == '[') ||
                (exp[i] == '}' && st.top() == '{')) {
                st.pop();
            }
            else return false;
        }
    }
    if (!st.empty()) return false;

    return true;
}

int main() {
    string exp = "{[()()[{(x)}]]}";

    cout << isBalanced(exp);

    return 0;
}
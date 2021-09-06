#include<stack>
#include<string>
#include<iostream>
#include<regex>

using namespace std;

bool checkPalindrome(const string& exp) {
    if (exp.length() == 0 || exp.length() == 1) return true;
    stack<char> st;
    int i;

    for (i = 0; i < exp.length() / 2; i++) {
        st.push(exp[i]);
    }

    for (i = (exp.length() + 1) / 2; i < exp.length() && !st.empty(); i++) {
        if (exp[i] != st.top()) return false;
        st.pop();
    }

    return true;
}

bool isBalanced(const string& exp) {
    stack<char> st;

    regex openingBrackets("([{");
    regex closingBrackets(")]}");

    for (int i = 0; i < exp.length(); i++) {
        string temp = exp.substr(i, 1);

        if (regex_match(temp, openingBrackets)) {
            st.push(exp[i]);
        }
        else if (regex_match(temp, closingBrackets)) {
            if ((exp[i] == ')' && st.top() == '(') ||
                (exp[i] == ']' && st.top() == '[') ||
                (exp[i] == '}' && st.top() == '}')) {
                st.pop();
            }
            else return false;
        }
    }

    return true;
}

int main() {
    string exp = "()(";

    cout << isBalanced(exp);

    return 0;
}
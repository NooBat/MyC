#include<stack>
#include<string>
#include<iostream>

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

int main() {
    string palindrome = "wontlovers";

    cout << checkPalindrome(palindrome);

    return 0;
}
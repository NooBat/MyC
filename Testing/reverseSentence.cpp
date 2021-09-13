#include<iostream>

using namespace std;

void recursive(string s, int idx, string& result, string& temp) {
    if (idx == 0) {
        string tmp = s.substr(idx, 1);
        temp = tmp + temp;
        result += temp;
        return;
    }

    if (s[idx] != ' ') {
        string tmp = s.substr(idx, 1);
        temp = tmp + temp;
    }
    else {
        result += temp + " ";
        temp.clear();
    }

    recursive(s, idx - 1, result, temp);
}

string reverseSentence(string s) {
    string result;
    string temp = "";

    recursive(s, s.length() - 1, result, temp);

    return result;
}

int main() {
    string s = "recursion is easy";

    cout << reverseSentence(s);

    return 0;
}
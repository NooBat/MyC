#include<iostream>

using namespace std;

void recursive(string s, int idx, string& result, string& word) {
    if (idx == 0) {
        string temp = s.substr(idx, 1);
        word = temp + word;
        result += word;
        return;
    }

    if (s[idx] != ' ') {
        string temp = s.substr(idx, 1);
        word = temp + word;
    }
    else {
        result += word + " ";
        word.clear();
    }

    recursive(s, idx - 1, result, word);
}

string reverseSentence(string s) {
    string result;
    string word = "";

    recursive(s, s.length() - 1, result, word);

    return result;
}

int main() {
    string s = "recursion is easy";

    cout << reverseSentence(s);

    return 0;
}
#include<bits/stdc++.h>

using namespace std;

int main() {
    string s;
    getline(cin, s);

    int numsOfLucky = 0;

    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '4' || s[i] == '7') {
            numsOfLucky++;
        }
    }

    string numsToString = to_string(numsOfLucky);
    bool lucky = true;

    for (int i = 0; i < numsToString.length() && lucky; i++) {
        if (numsToString[i] != '4' && numsToString[i] != '7') {
            lucky = false;
        }
    }

    if (lucky) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}
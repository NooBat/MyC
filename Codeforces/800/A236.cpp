#include<bits/stdc++.h>

using namespace std;

int main() {
    string username;
    getline(cin, username);

    int count = 0;
    bool hash[26] = { false };

    for (int i = 0; i < username.length(); i++) {
        if (!hash[username[i] - 'a']) {
            count++;
            hash[username[i] - 'a'] = true;
        }
    }

    if (count % 2 == 0) {
        cout << "CHAT WITH HER!" << endl;
    } else {
        cout << "IGNORE HIM!" << endl;
    }

    return 0;
}
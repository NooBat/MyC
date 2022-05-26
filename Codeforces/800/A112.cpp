#include<bits/stdc++.h>

using namespace std;

int main() {
    string s1, s2;
    getline(cin, s1);
    getline(cin, s2);

    for (int i = 0; i < s1.length(); i++) {
        s1[i] = tolower(s1[i]);
        s2[i] = tolower(s2[i]);
    }

    int result = 0;

    for (int i = 0; i < s1.length() && result == 0; i++) {
        if (s1[i] < s2[i]) {
            result = -1;
        } else if (s1[i] > s2[i]) {
            result = 1;
        }
    }

    cout << result << endl;

    return 0;
}
#include<bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    cin.ignore();

    string s;
    getline(cin, s);

    int stonesToTakeOut = 0;
    
    for (int i = 1; i < n; i++) {
        if (s[i - 1] == s[i]) {
            stonesToTakeOut++;
        }
    }

    cout << stonesToTakeOut << endl;

    return 0;
}
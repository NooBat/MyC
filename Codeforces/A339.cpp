#include<bits/stdc++.h>

using namespace std;

int main() {
    string s;
    getline(cin, s);

    int arr[s.length() / 2 + 1];

    for (int i = 0; i < s.length(); i += 2) {
        arr[i / 2] = s[i] - '0';
    }

    sort(arr, arr + (sizeof(arr) / sizeof(arr[0])));

    for (int i = 0; i < s.length(); i += 2) {
        s[i] = arr[i / 2] + '0';
    }

    cout << s << endl;

    return 0;
}
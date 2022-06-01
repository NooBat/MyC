#include<bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;

    int candies[n];
    for (int i = 0; i < n; i++) {
        cin >> candies[i];
    }

    int sum = 0;

    for (int i = 0; i < n; i++) {
        sum += candies[i];
    }

    if (sum % 2 != 0) {
        cout << "NO" << endl;
    } else {
        
    }
}

int main() {
    int testcases;
    cin >> testcases;

    while (testcases--) {
        solve();
    }

    return 0;
}
#include<bits/stdc++.h>

using namespace std;

int main() {
    int bills[5] = {1, 5, 10, 20, 100};
    int balance;
    cin >> balance;
    int minBills = 0;

    for (int i = 4; i >= 0 && balance > 0; i--) {
        if (balance >= bills[i]) {
            minBills += balance / bills[i];
            balance %= bills[i];
        }
    }

    cout << minBills << endl;

    return 0;
}
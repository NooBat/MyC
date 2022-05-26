#include<bits/stdc++.h>

using namespace std;

int main() {
    int bills[5] = {1, 5, 10, 20, 100};
    int balance;
    cin >> balance;
    int minBills[balance + 1];
    minBills[0] = 0;

    for (int i = 1; i <= balance; i++) {
        minBills[i] = INT_MAX;
    }

    for (int i = 1; i <= balance; i++) {
        for (int j = 0; j < 5; j++) {
            if (bills[j] <= i && minBills[i - bills[j]] + 1 <= minBills[i]) {
                minBills[i] = minBills[i - bills[j]] + 1;
            }
        }
    }

    cout << minBills[balance] << endl;

    return 0;
}
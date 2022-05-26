#include<bits/stdc++.h>

using namespace std;

int main() {
    int bananaPrice, initialMoney, numberOfBananas;
    cin >> bananaPrice >> initialMoney >> numberOfBananas;

    int totalPay = (numberOfBananas * (numberOfBananas + 1) / 2) * bananaPrice;
    if (totalPay <= initialMoney) {
        cout << 0 << endl;
    } else {
        cout << totalPay - initialMoney << endl;
    }

    return 0;
}
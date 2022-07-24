#include<bits/stdc++.h>

using namespace std;

int main() {
    int i = -1;
    int times = -1;

    while (i != 1 && times < 25) {
        cin >> i;
        times++;
    }

    int rowIndex = times / 5;
    int columnIndex = times % 5;

    cout << abs(2 - rowIndex) + abs(2 - columnIndex) << endl;

    return 0;
}
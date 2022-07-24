#include<bits/stdc++.h>

using namespace std;

int main() {
    int numberOfTrams, getOn, getOff;
    int numberOfPassenger = 0;
    int minCapacity = 0;

    cin >> numberOfTrams;
    
    while (numberOfTrams--) {
        cin >> getOff >> getOn;

        numberOfPassenger = numberOfPassenger - getOff + getOn;

        if (numberOfPassenger > minCapacity) {
            minCapacity = numberOfPassenger;
        }
    }

    cout << minCapacity << endl;

    return 0;
}
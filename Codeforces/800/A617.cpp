#include<bits/stdc++.h>

using namespace std;

int main() {
    int x;
    cin >> x;

    int minSteps[x + 1];
    minSteps[0] = 0;
    for (int i = 1; i <= x; i++) {
        minSteps[i] = INT_MAX;
    }

    int steps[5] = {1, 2, 3, 4, 5};

    for (int i = 1; i <= x; i++) {
        for (int j = 0; j < 5; j++) {
            if (steps[j] <= i && minSteps[i - steps[j]] + 1 < minSteps[i]) {
                minSteps[i] = minSteps[i - steps[j]] + 1;
            }
        }
    }

    cout << minSteps[x] << endl;

    return 0;
}
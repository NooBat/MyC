#include<bits/stdc++.h>

using namespace std;

int main() {
    int n, k;
    int* scores;

    cin >> n >> k;
    scores = new int[n];

    for (int i = 0; i < n; i++) {
        cin >> scores[i];
    }

    int toNextRound = 0;
    int threshold = scores[k - 1];

    for (int i = 0; i < n; i++) {
        if (scores[i] > 0 && scores[i] >= threshold) {
            toNextRound++;
        }
    }

    cout << toNextRound << endl;


    return 0;
}
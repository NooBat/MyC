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

    sort(scores, scores + n, greater<int>());

    int toNextRound = 0;
    int threshold = scores[k];

    for (int i = 0; i < n && scores[i] > 0; i++) {
        if (scores[i] >= threshold) {
            toNextRound++;
        }
    }

    cout << toNextRound << endl;


    return 0;
}
#include<bits/stdc++.h>

using namespace std;

int main() {
    int n;

    cin >> n;

    int solvableProblems = 0;

    for (int i = 0; i < n; i++) {
        int numberOfFriends = 0;
        for (int j = 0; j < 3; j++) {
            int temp;
            cin >> temp;

            numberOfFriends += temp;
        }

        if (numberOfFriends >= 2) {
            solvableProblems++;
        }
    }

    cout << solvableProblems << endl;

    return 0;
}
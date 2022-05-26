#include<bits/stdc++.h>

using namespace std;

int main() {
    int limak, bob;
    cin >> limak >> bob;

    int years = 0;

    for (; limak <= bob; years++) {
        limak *= 3;
        bob *= 2;
    }

    cout << years << endl;

    return 0;
}
#include<iostream>

using namespace std;

/** Calculates the sum of the squares from 1 to n.
 * @param n as integer.
 * @post returns sum of 1^2 + 2^2 + ... + n^2 */
int sumSquares(int n) {
    if (n <= 0) return -1;
    if (n == 1) return 1;

    return n * n + sumSquares(n - 1);
}

int main() {
    int n;
    cin >> n;

    cout << sumSquares(n);
    return 0;
}

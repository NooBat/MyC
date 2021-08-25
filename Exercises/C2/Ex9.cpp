#include<iostream>

using namespace std;

/** Writes the digits of a positive decimal integer in reverse order.
 * @pre n must be positive integer.
 * @param n is an integer to be reversed.
 * @post A line of reversed digits. */
void reverseDigits(int n) {
    if (n <= 0) return;

    cout << (n % 10);
    reverseDigits(n / 10);
}

int main() {
    int n;
    do {
        cin >> n;
    }
    while (n <= 0);

    reverseDigits(n);

    return 0;
}
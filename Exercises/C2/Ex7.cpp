#include<iostream>

using namespace std;

/** Writes integer from 1 to n.
 * @pre n must be greater than 1.
 * @param n as integer.
 * @post NONE. */
void writeInteger(int n) {
    if (n == 1) {
        cout << 1 << " ";
        return;
    }
    writeInteger(n - 1);
    
    cout << n << " ";
}

int main() {
    int n;
    cin >> n;

    writeInteger(n);
    return 0;
}
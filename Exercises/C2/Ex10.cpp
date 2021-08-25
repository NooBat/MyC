#include<iostream>

using namespace  std;

/** Writes character a for n times. 
 * @param a as char @param n as integer.
 * @post NONE. */
void writeLine(char a, int n) {
    if (n < 1) return;

    cout << a;
    writeLine(a, n - 1);
}

/** Writes m lines of character a for n times.
 * @param a as character @param n as integer for number of times to print a
 * @param m as number of lines
 * @post NONE. */
void writeBlock(char a, int n, int m) {
    if (m < 1) return;

    writeLine(a, n);
    cout << endl;
    writeBlock(a, n, m - 1);
}

int main() {
    char a;
    int n;
    int m;

    cin >> a >> n >> m;

    writeLine(a, n);
    cout << endl << endl;

    writeBlock(a, n, m);

    return 0;
}
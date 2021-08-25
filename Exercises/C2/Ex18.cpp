#include<iostream>

using namespace std;

/** Returns the value of x raised to nth power.
 * @pre n >= 0.
 * @post returns the computed value. */
double power1(double x, int n) {
    double power = 1.0;

    for (int i = 0; i < n; i++) {
        power *= x;
    }

    return power;
}

/** Returns the value of x raised to nth power.
 * @pre n >= 0.
 * @post returns the computed value. */
double power2(double x, int n) {
    if (n < 0) return -999;

    if (n == 0) return 1;

    return x * power2(x, n - 1);
}

/** Returns the value of x raised to nth power.
 * @pre n >= 0.
 * @post returns the computed value. */
double power3(double x, int n) {
    if (n < 0) return -999;

    if (n == 0) return 1;

    double halfPower = power3(x, n / 2);

    if (n % 2 == 0) return halfPower * halfPower;

    return x * halfPower * halfPower; 
}

int main() {
    cout << power1(2.5, 2) << endl;
    cout << power2(2.5, 2) << endl;
    cout << power3(2.5, 2) << endl;
    
    return 0;
}
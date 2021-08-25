#include<iostream>

using namespace std;

int arr[10000] = {1, 1, 1, 3, 5, 0};

/** Returns value for f(n) = f(n - 1) + 3 * f(n - 5). 
 * @pre n > 0.
 * @post returns value. */
int f(int n) {
    if (n <= 0) return -999;

    if (arr[n - 1] != 0) return arr[n - 1];
    arr[n - 1] = f(n - 1) + 3 * f(n - 5);

    return arr[n - 1];
}

int main() {
    cout << f(6) << endl;
    cout << f(7) << endl;
    cout << f(8) << endl;
    cout << f(15) << endl;
    
    return 0;
}

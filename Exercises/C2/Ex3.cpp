#include<iostream>

using namespace std;

/** Computates sum of the first n integers in an array.
 * @param Array of integers with the first n integers.
 * @pre n >= 1 and array's number of elements >= n.
 * @post returns the sum of the first n integers recursively. */
int sumArray(int arr[], int n) {
    if (n <= 0) return 0;
    if (n == 1) return arr[0];
    return arr[n - 1] + sumArray(arr, n - 1);
}

int main() {
    int n, arraySize;
    cin >> arraySize;
    
    int arr[arraySize];
    for (int i = 0; i < arraySize; i++) {
        cin >> arr[i];
    }

    cin >> n;

    cout << sumArray(arr, n);

    return 0;
}

#include<iostream>

using namespace std;

int maxArray(int *arr, int l, int r) {
    if (l == r) return arr[l];

    int mid = l + (r - l) / 2;
    
    return max(maxArray(arr, l, mid), maxArray(arr, mid + 1, r));
}

int main() {
    int n;
    cin >> n;

    int *arr = new int[n];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << maxArray(arr, 0, n - 1);

    return 0;
}
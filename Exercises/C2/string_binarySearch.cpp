#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

bool binarySearch(string arr[], int n, string key) {
    if (n == 0) return false;

    int l = 0;
    int r = n - 1;
    
    int mid;

    while (l <= r) {
        mid = l + (r - l) / 2;
        if (arr[mid] == key) return true;

        else if (arr[mid] > key) r = mid - 1;

        else l = mid + 1;
    }

    return false;
}

int main() {
    int n;
    cin >> n;
    
    string arr[n];

    cin.ignore();
    for (int i = 0; i < n; i++) {
        getline(cin, arr[i]);
    }

    sort(&arr[0], &arr[0] + n);

    string key;
    getline(cin, key);

    cout << binarySearch(arr, n, key);

    return 0;
}
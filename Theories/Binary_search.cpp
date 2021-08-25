#include<iostream>

using namespace std;

int main() {
    int arr[1000];
    int n;

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int key;
    cin >> key;
    int l = 0;
    int r = n - 1;
    bool result = false;

    while (l <= r) {
        int mid = l + r / 2;
        if (arr[mid] == key) result = true;
        else if (key < arr[mid]) {
            r = mid - 1;
        }
        else l = mid + 1;
    }

    if (!result) {
        cout << "True";
    }
    else cout << "False";

    return 0;
}
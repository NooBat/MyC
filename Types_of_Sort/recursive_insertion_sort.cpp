#include<iostream>

using namespace std;

void insertion_sort(int arr[], int n) {
    if (n == 1) return;

    int last = arr[n - 1];
    int j = n - 2;
    
    while(j >= 0 && last < arr[j]) {
        arr[j + 1] = arr[j];
        j--;
    }
    arr[j + 1] = last;

    insertion_sort(arr, n - 1);
}

void print_array(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int T, n, arr[1000];
    
    cout << "Input number of testcase(s): ";
    cin >> T;

    while(T--) {
        cout << "Testcase: " << T << endl;
        cout << "Input number of element(s): ";
        cin >> n;
        
        cout << "Input array value(s): ";
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        cout << "Array before sort: ";
        print_array(arr, n);

        insertion_sort(arr, n);
        cout << "Array after sort: ";
        print_array(arr, n);
    }
    
    return 0;
}
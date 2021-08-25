#include<iostream>

using namespace std;

void bubble_sort(int arr[], int n) {
    if (n == 1) return;

    //One pass of bubble sort, after
    //this, the last element will be 
    //in the right position
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            swap(arr[i], arr[i + 1]);
        }
    }
    //Then calls the function recursively
    //without the last element
    bubble_sort(arr, n - 1);
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

        bubble_sort(arr, n);
        cout << "Array after sort: ";
        print_array(arr, n);
    }
    
    return 0;
}
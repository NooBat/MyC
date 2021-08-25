#include<iostream>

using namespace std;
//quick sort:
// - a "divide and conquer" algorithm
// - pick an element as a pivot
// - partition the array around picked pivot 
// - target of partition is put the picked pivot in the correct position
// - put smaller elements to the left side of the pivot and other to the right side

int partition(int arr[], int l, int r) {
    int pivot = arr[r];

    int i = l - 1;

    for (int j = l; j < r; j++) {
        //If current element smaller than pivot 
        if (arr[j] < pivot) {
            i += 1; //increase index of smaller element
            swap(arr[i], arr[j]); 
        } 
    }
    swap(arr[i + 1], arr[r]);
    return (i + 1);
}

void quick_sort(int arr[], int l, int r) {
    if (l >= r) return;

    int pi = partition(arr, l, r);
    quick_sort(arr, l, pi - 1);
    quick_sort(arr, pi + 1, r);
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

        quick_sort(arr, 0, n - 1);
        cout << "Array after sort: ";
        print_array(arr, n);
    }
    
    return 0;
}
#include<iostream>

using namespace std;
//insertion sort:
// - iterate from arr[1] to arr[n - 1]
// - compare the current element (key) to its predecessor
// - if key <= predecessor, compare key to the elements before
// - move the greater elements one position up to make space    4 5 1 3 2 

void insertion_sort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        
        
        while(j >= 0 && key < arr[j]) {
            // Move the array one element up
            // while checking predecessor
            arr[j + 1] = arr[j];
            j -= 1;
        }
        arr[j + 1] = key;
    }
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
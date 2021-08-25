#include<iostream>

using namespace std;
//selection sort:
// - select the minimum element in the unsorted array
// - swap and place it at the beginning of the unsorted array

// - time complexity: O(n ^ 2) because they use two nested loops
// - auxiliary space: O(1) 
void selection_sort(int arr[], int n) {
    int min_idx = 0;

    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j; 
            }
        }
        swap(arr[i], arr[min_idx]);
    }
}

//function to print array
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

        selection_sort(arr, n);
        cout << "Array after sort: ";
        print_array(arr, n);
    }
    
    return 0;
}
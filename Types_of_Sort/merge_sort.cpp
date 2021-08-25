#include<iostream>

using namespace std;
//merge sort:
// - a "divide and conquer" algorithm
// - divide the array into half until the array' size is 1
// - compare and merge the subarrays back with the right order
// - auxiliary space: O(n)

void merge(int arr[], int l, int r, int mid) {
    //n1 is the number of elements in the first half
    int n1 = mid - l + 1;
    //n2 is the number of elements in the second half
    int n2 = r - mid;

    int idx = l;
    int array1_idx = 0;
    int array2_idx = 0;

    //initializes two subarrays for the first and second half
    int *L = new int[n1];
    int *R = new int[n2];

    //initializes values for two subarrays
    for (int i = 0; i < n1; i++) {
        L[i] = arr[l + i];
    }
    for (int i = 0; i < n2; i++) {
        R[i] = arr[mid + 1 + i];
    }
    
    //Merge and sort the subarrays into one
    while(array1_idx < n1 && array2_idx < n2) {
        if (L[array1_idx] <= R[array2_idx]) {
            arr[idx] = L[array1_idx];
            array1_idx++;
        }
        else {
            arr[idx] = R[array2_idx];
            array2_idx++;
        }
        idx++;
    }

    //In case the first subarray
    //still have values
    while(array1_idx < n1) {
        arr[idx] = L[array1_idx];
        idx++;
        array1_idx++;
    }

    //In case the second subarray
    //still have values
    while(array2_idx < n2) {
        arr[idx] = R[array2_idx];
        idx++;
        array2_idx++;
    }
    
}

void merge_sort(int arr[], int left, int right) {
    if (left >= right) return;
    
    int mid = (left + right) / 2;
    merge_sort(arr, left, mid);
    merge_sort(arr, mid + 1, right);
    merge(arr, left, right, mid);
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

        merge_sort(arr, 0, n - 1);
        cout << "Array after sort: ";
        print_array(arr, n);
    }
    
    return 0;
}
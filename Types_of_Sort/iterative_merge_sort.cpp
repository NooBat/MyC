#include<iostream>

using namespace std;
int min(int &x, int &y) {
    return (x > y) ? (y) : (x);
}
void merge(int arr[], int l, int r, int mid) {
    int n1 = mid - l + 1;
    int n2 = r - mid; 

    int L[n1], R[n2];

    int idx = l;
    int idx1 = 0, idx2 = 0;

    while(idx1 < n1 && idx2 < n2) {
        if (L[idx1] < R[idx2]) {
            arr[idx] = L[idx1];
            idx1++;
        }
        else {
            arr[idx] = R[idx2];
            idx2++;
        }
        idx++;
    }

    while(idx1 < n1) {
        arr[idx] = L[idx1];
        idx1++;
        idx++;
    }
    
    while(idx2 < n2) {
        arr[idx] = R[idx2];
        idx2++;
        idx++;
    }

}

void merge_sort(int arr[], int n) {
    int curr_size;
    int left_start;

    for (curr_size = 1; curr_size < n; curr_size *= 2) {
        for (left_start = 0; left_start < n - 1; left_start += 2 * curr_size) {
            int mid = min(left_start + curr_size - 1, n - 1);

            int right_end = min(left_start + 2 * curr_size - 1, n - 1);  

            merge(arr, left_start, right_end, mid);      
        }
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

        merge_sort(arr, n - 1);
        cout << "Array after sort: ";
        print_array(arr, n);
    }
    
    return 0;
}
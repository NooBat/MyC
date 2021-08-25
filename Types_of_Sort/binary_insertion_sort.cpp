#include<iostream>

using namespace std;

int binary_search(int arr[], int low, int high, int key) {
    if (low >= high) return (key > arr[low]) ? (low + 1) : (low);

    int mid = low + high / 2;
    if (arr[mid] == key) {
        return mid + 1;
    }
    else if (arr[mid] > key) {
        return binary_search(arr, low, mid - 1, key);
    }
    return binary_search(arr, mid + 1, high, key);
}
void insertion_sort(int arr[], int n) {
    int i, j, key, loc;
    for (int i = 1; i < n; i++) {
        j = i - 1;
        key = arr[i];

        loc = binary_search(arr, 0, j, key);
        while (j >= loc) {
            arr[j + 1] = arr[j];
            j--;
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
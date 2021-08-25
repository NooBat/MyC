#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
//radix sort:
// - sort the array digit by digit using any stable sort
// - preferably counting sort (since digit varies from 0 to 9)

void counting_sort(vector<int> &arr, int exp) {
    vector<int> output(arr.size());
    int count[10] = { 0 };

    for (int i = 0; i < arr.size(); i++) {
        count[(arr[i] / exp) % 10]++;
    }

    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    for (int i = arr.size() - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        --count[(arr[i] / exp) % 10];
    }

    for (int i = 0; i < arr.size(); i++) {
        arr[i] = output[i];
    }
}

void radix_sort(vector<int> &arr) {
    int M = *max_element(arr.begin(), arr.end());

    for (int exp = 1; M / exp > 0; exp *= 10) {
        counting_sort(arr, exp);
    }
}

void print_array(vector<int> arr, int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int T, n;
    
    cout << "Input number of testcase(s): ";
    cin >> T;

    while(T--) {
        cout << "Testcase: " << T << endl; 
        cout << "Input number of element(s): ";
        cin >> n;
        
        vector<int> arr(n);
        cout << "Input array value(s): ";
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        cout << "Array before sort: ";
        print_array(arr, n);

        radix_sort(arr);

        cout << "Array after sort: ";
        print_array(arr, n);
    }
    
    return 0;
}
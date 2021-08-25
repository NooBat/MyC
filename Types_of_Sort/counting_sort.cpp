#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
//counting sort:
// - a sorting technique based on keys between a specific range
// - works by counting the number of objects having distinct key values
// - calculate the position of each object in the output sequence

void counting_sort(vector<int> &arr) {
    int M = *max_element(arr.begin(), arr.end());
    int m = *min_element(arr.begin(), arr.end());
    int range = M - m + 1;

    vector<int> count(range);
    vector<int> output(arr.size());

    for (int i = 0; i < arr.size(); i++) {
        count[arr[i] - m]++;
    }

    for (int i = 1; i < range; i++) {
        count[i] += count[i - 1];
    }

    for (int i = arr.size() - 1; i >= 0; i--) {
        output[count[arr[i] - m] - 1] = arr[i];
        --count[arr[i] - m];
    }

    for (int i = 0; i < arr.size(); i++) {
        arr[i] = output[i];
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

        counting_sort(arr);
        cout << "Array after sort: ";
        print_array(arr, n);
    }
    
    return 0;
}
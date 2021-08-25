#include<iostream>

using namespace std;

int partition(int arr[], int l, int r) {
    int idx1 = l - 1;
    int idx2 = r + 1;

    int pivot = arr[l];

    while (idx1 < idx2) {
        idx1++;
        
        while (arr[idx1] <= pivot && idx1 < r) {
            idx1++;
        }
        
        idx2--;
        while(arr[idx2] >= pivot && idx2 > l) {
            idx2--;
        }

        if (idx1 >= idx2) {
            swap(arr[l], arr[idx2]);            
            break;
        }

        swap(arr[idx1], arr[idx2]);
    }

    return idx2;
}

int kSmall(int arr[], int n, int k) {
    if (n == 0) return -1;
    if (n == 1) return arr[0];
    if (k > n || k <= 0) {
        cout << "Out of bound\n";
        return -1;
    } 

    int l = 0;
    int r = n - 1;
    int pivotIdx;
    while (l <= r) {
        pivotIdx = partition(arr, l, r);
        if (k == pivotIdx - l + 1) return arr[pivotIdx];

        else if (k < pivotIdx - l + 1) {
            r = pivotIdx - 1;    
        }
        else if (k > pivotIdx - l + 1) l = pivotIdx + 1;
    }

    return arr[pivotIdx];
}

int main() {
    int n;
    cin >> n;

    int arr[n];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int k;
    cin >> k;

    cout << kSmall(arr, n, k) << endl;
    
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}
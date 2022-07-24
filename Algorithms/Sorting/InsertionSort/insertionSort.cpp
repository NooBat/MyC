#include<bits/stdc++.h>
#include "../../../arrayPrinter.hpp"

using namespace std;

template<class T>
class InsertionSort {
public:
    void insertionSort(T arr[], int n) {
        for (int i = 1; i < n; i++) {
            // find the correct position for ith element
            int j = i;
            while (j > 0 && arr[i] < arr[j - 1]) j--;
            
            // move it to the correct position
            int temp = arr[i];
            for (int k = i; k > j; k--) {
                arr[k] = arr[k - 1];
            }

            arr[j] = temp;
        }
    }
};

int main() {
    int arr[] = {19, 12, 4, 133, 200};
    int size = sizeof(arr) / sizeof(arr[0]);

    printArr<int>(arr, size);

    InsertionSort<int> sorter;

    sorter.insertionSort(arr, size);

    printArr<int>(arr, size);

    return 0;
}
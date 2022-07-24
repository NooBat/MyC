#include<bits/stdc++.h>
#include "../../../arrayPrinter.hpp"

using namespace std;

template<class T>
class MergeSort {
private:
    void mergeSortUtil(T arr[], int left, int right) {
        if (left >= right) {
            // if the array has 1 element, return it
            return;
        }

        int mid = left + (right - left) / 2;
        // sort the two smaller segments
        mergeSortUtil(arr, left, mid);
        mergeSortUtil(arr, mid + 1, right);
        
        // merge the segments back together
        // i: idx for the left segment, j: idx for the right segment and idx is the index for the merging array
        int i = left;
        int j = mid + 1;
        int idx = 0;
        // tempArr: merging array
        int *tempArr = new T[right - left + 1];
        while (i <= mid || j <= right) {
            if (i > mid) {
                // if the left part has no more elements
                tempArr[idx++] = arr[j++];
            } else if (j > right) {
                // if the right part has no more elements
                tempArr[idx++] = arr[i++];
            } else if (arr[i] <= arr[j]) {
                // if the left part has the smaller element
                tempArr[idx++] = arr[i++];
            } else {
                // if the right part has the smaller element
                tempArr[idx++] = arr[j++];
            }
        }

        // copy the merging array content back to the original array
        for (int i = 0; i < idx; i++) {
            arr[left + i] = tempArr[i];
        }

        delete[] tempArr;
        tempArr = nullptr;
    }
public:
    void mergeSort(T arr[], int n) {
        if (n <= 1) {
            return;
        } else {
            mergeSortUtil(arr, 0, n - 1);     
        }
    }
};

int main() {
    int arr[] = {19, 12, 4, 133, 200};
    int size = sizeof(arr) / sizeof(arr[0]);

    printArr<int>(arr, size);

    MergeSort<int> sorter;

    sorter.mergeSort(arr, size);

    printArr<int>(arr, size);

    return 0;
}
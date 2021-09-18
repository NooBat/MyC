#ifndef _MERGE_SORT
#define _MERGE_SORT

#include<iostream>
#include<vector>

using namespace std;
//merge sort:
// - a "divide and conquer" algorithm
// - divide the array into half until the array' size is 1
// - compare and merge the subarrays back with the right order
// - auxiliary space: O(n)

template<class ItemType>
class MergeSort 
{
private:
    /** Merges two sorted array segments arr[first..mid] 
     * and arr[mid+1..last] into one sorted array.
     * @pre first <= mid <= last. The subarrays arr[first..mid] and 
     * arr[mid+1..last] are each sorted in increasing order.
     * @post arr[first..last] is sorted.
     * @param arr The given array.
     * @param first The index of the beginning of the first segment in arr.
     * @param mid The index of the end of the first segment in arr;
     * mid + 1 marks the beginning of the second segment.
     * @param last The index of the last element in the second segment in arr.
     * @note This function merges the two subarrays into a temporary array 
     * and copies the result into the original array arr. */
    void merge(ItemType arr[], int first, int mid, int last);

public:
    /** Sorts the items in an array into ascending order.
     * @pre arr[first..last] is an array.
     * @post arr[first..last] is sorted in ascending order.
     * @param arr The given array.
     * @param first The index of the first element to consider in arr. 
     * @param last The index of the last element to consider in arr. */
    void mergeSort(ItemType arr[], int first, int last);
};

template<class ItemType>
void MergeSort<ItemType>::merge(ItemType arr[], int first, int mid, int last) 
{
    vector<ItemType> tempArray;

    int first1 = first;
    int last1 = mid;

    int first2 = mid + 1;
    int last2 = last;

    while (first1 <= last1 && first2 <= last2) 
    {
        if (arr[first1] >= arr[first2]) 
        {
            tempArray.push_back(arr[first2]);
            first2++;
        }
        else 
        {
            tempArray.push_back(arr[first1]);
            first1++;
        }
    }

    while (first1 <= last1) 
    {
        tempArray.push_back(arr[first1]);
        first1++;
    }

    while (first2 <= last2) 
    {
        tempArray.push_back(arr[first2]);
        first2++;
    }

    for (int i = 0; i < tempArray.size(); i++) 
    {
        arr[first + i] = tempArray[i];
    }
}

template<class ItemType>
void MergeSort<ItemType>::mergeSort(ItemType arr[], int first, int last) 
{
    if (first >= last) return;

    int mid = first + (last - first) / 2;

    mergeSort(arr, first, mid);

    mergeSort(arr, mid + 1, last);

    merge(arr, first, mid, last);
}







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

// void print_array(int arr[], int n) {
//     for (int i = 0; i < n; i++) {
//         cout << arr[i] << " ";
//     }
//     cout << endl;
// }

#endif

// int main() {
//     int arr[] = {9, 10, 1983, 129, 1992, 12041, 12388, 28, 29, -129, 129, 121848, 28, 283, 221, 393, 4, 3, 0, 0, 445, 567};

//     int size = (int)(sizeof(arr) / sizeof(arr[0]));

//     MergeSort<int> sortFunc;

//     sortFunc.mergeSort(arr, 0, size - 1);

//     print_array(arr, size);
    
//     return 0;
// }
#ifndef _SELECTION_SORT
#define _SELECTION_SORT
#include<iostream>

using namespace std;
//selection sort:
// - select the minimum element in the unsorted array
// - swap and place it at the beginning of the unsorted array

// - time complexity: O(n ^ 2) because they use two nested loops
// - auxiliary space: O(1) 
template<class T>
void selectionSort1(T arr[], int n) 
{
    int min_idx = 0;

    for (int i = 0; i < n; i++) 
    {
        for (int j = i; j < n; j++) 
        {
            if (arr[j] < arr[min_idx]) 
            {
                min_idx = j; 
            }
        }
        swap(arr[i], arr[min_idx]);
    }
}

template<class T>
int findMaxIndex(T arr[], int n);

template<class T>
void selectionSort2(T arr[], int n) 
{
    for (int last = n - 1; last >= 1; last--) 
    {
        int maxElementIndex = findMaxIndex(arr, last + 1);

        swap(arr[last], arr[maxElementIndex]);
    }
}

template<class T>
int findMaxIndex(T arr[], int size) 
{
    T max = arr[0];
    int result = 0;

    for (int idx = 1; idx < size; idx++) 
    {
        if (arr[idx] > max) 
        {
            max = arr[idx];
            result = idx;
        }
    }

    return result;
}

//function to print array
void print_array(int arr[], int n) 
{
    for (int i = 0; i < n; i++) 
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// int main() {
//     int arr[] = {29, 10, 33, 14, 20, 21};

//     int size = (int)(sizeof(arr) / sizeof(arr[0]));

//     selectionSort2(arr, size);

//     print_array(arr, size);

//     return 0;
// }
#endif